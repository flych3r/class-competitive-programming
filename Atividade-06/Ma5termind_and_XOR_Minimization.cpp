// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/ma5termind-and-xor-minimization/

// C++ program for a Trie based O(n) solution to find max
// subarray XOR
#include<bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
const int SIZE = 1e5 + 1;
// Assumed int size
#define INT_SIZE 32

// A Trie Node
struct TrieNode {
    int value; // Only used in leaf nodes
    TrieNode * arr[2];
    int count;
};

// Utility function to create a Trie node
TrieNode * newNode() {
    TrieNode * temp = new TrieNode;
    temp -> value = 0;
    temp -> arr[0] = temp -> arr[1] = NULL;
    return temp;
}

// Inserts pre_xor to trie with given root
void insert(TrieNode * root, pii pre_xor) {
    TrieNode * temp = root;

    // Start from the msb, insert all bits of
    // pre_xor into Trie
    for (int i = INT_SIZE - 1; i >= 0; i--) {
        // Find current bit in given prefix
        bool val = pre_xor.first & (1 << i);

        // Create a new node if needed
        if (temp -> arr[val] == NULL)
            temp -> arr[val] = newNode();

        temp = temp -> arr[val];
    }

    // Store value at leaf node
    temp -> value = pre_xor.first;
    temp -> count = pre_xor.second;
}

// Finds the maximum XOR ending with last number in
// prefix XOR 'pre_xor' and returns the XOR of this maximum
// with pre_xor which is maximum XOR ending with last element
// of pre_xor.
pii query(TrieNode * root, int pre_xor) {
    TrieNode * temp = root;
    for (int i = INT_SIZE - 1; i >= 0; i--) {
        // Find current bit in given prefix
        bool val = pre_xor & (1 << i);

        // Traverse Trie, first look for a
        // prefix that has opposite bit
        if (temp -> arr[val] != NULL)
            temp = temp -> arr[val];

        // If there is no prefix with opposite
        // bit, then look for same bit.
        else if (temp -> arr[1 - val] != NULL)
            temp = temp -> arr[1 - val];
    }
    // return pre_xor ^ (temp -> value);
    return make_pair(temp->value, temp->count);
}

// Driver program to test above functions
int main() {
    int n, q, x;

    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector <int> possible;

    possible.assign(SIZE, 0LL);

    possible[0] = 1;

    int maxsize = 0;
    for(int i = 0; i < n; i++){
        for(int j = maxsize; j >= 0; j--){
            if(possible[j]){
                possible[j + arr[i]] = (possible[j + arr[i]] + possible[j])%MOD;
                maxsize = max( maxsize, j + arr[i] );
            }
        }
    }

    struct TrieNode *root = newNode();
    for (int i = SIZE; i > 0; i--)
    {
        if (possible[i]) insert(root, make_pair(i, possible[i]));
    }

    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &x);
        pii ans = query(root, x);
        printf("%d %d\n", ans.first, ans.second);
        // cout << ans.first << ' ' << ans.second << endl;
    }

    return 0;
}
