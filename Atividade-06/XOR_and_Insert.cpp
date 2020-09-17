// https://www.hackerearth.com/pt-br/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/xor-and-insert-92b9b529/

// C++ program for a Trie based O(n) solution to find max
// subarray XOR
#include<bits/stdc++.h>
using namespace std;

// Assumed int size
#define INT_SIZE 32

// A Trie Node
struct TrieNode
{
    int value; // Only used in leaf nodes
    TrieNode *arr[2];
};

// Utility function to create a Trie node
TrieNode *newNode()
{
    TrieNode *temp = new TrieNode;
    temp->value = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}

// Inserts pre_xor to trie with given root
void insert(TrieNode *root, int pre_xor)
{
    TrieNode *temp = root;

    // Start from the msb, insert all bits of
    // pre_xor into Trie
    for (int i=INT_SIZE-1; i>=0; i--)
    {
        // Find current bit in given prefix
        bool val = pre_xor & (1<<i);

        // Create a new node if needed
        if (temp->arr[val] == NULL)
            temp->arr[val] = newNode();

        temp = temp->arr[val];
    }

    // Store value at leaf node
    temp->value = pre_xor;
}

// Finds the maximum XOR ending with last number in
// prefix XOR 'pre_xor' and returns the XOR of this maximum
// with pre_xor which is maximum XOR ending with last element
// of pre_xor.
int query(TrieNode *root, int pre_xor)
{
    TrieNode *temp = root;

    for (int i=INT_SIZE-1; i>=0; i--)
    {
        // Find current bit in given prefix
        bool val = pre_xor & (1<<i);

        // Traverse Trie, first look for a
        // prefix that has opposite bit
        if (temp->arr[val]!=NULL)
            temp = temp->arr[val];

        // If there is no prefix with opposite
        // bit, then look for same bit.
        else if (temp->arr[1-val] != NULL)
            temp = temp->arr[1-val];
    }
    return pre_xor^(temp->value);
}


// Driver program to test above functions
int main()
{
    int q, o, x;
    cin >> q;
    int arr[q];
    int xor_sum = 0;

    TrieNode *root = newNode();
    insert(root, xor_sum);

    while (q--)
    {
        cin >> o;
        if (o == 1)
        {
            cin >> x;
            insert(root, x ^ xor_sum);
        }
        if (o == 2)
        {
            cin >> x;
            xor_sum ^= x;
        }
        if (o == 3)
        {
            cout << query(root, xor_sum) << endl;
        }
    }

    return 0;
}

/*
xor_sum = 0
1 x: você adiciona na trie (x^xor_sum)
2 y: xor_sum = xor_sum ^ y
3: procura o minimo com  o xor_sum

Exemplo:
1 2
1 3
2 7
1 6
2 9
1 5
3

Na trie, você terá os seguintes valores
{2,3,6^7, 5^7^9}
Observe que quando você for procurar o minimo o xor_sum vale 7^9
Ele vai pegar o minimo entre
{2^7^9, 6^9, 5}
Observe que nesta técnica, você faz a operação de maneira lazy(preguiçosa).
*/