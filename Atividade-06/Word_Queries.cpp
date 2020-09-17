// https://www.hackerearth.com/pt-br/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/dummy4-2/

// C++ implementation of search and insert
// operations on Trie
#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
    int n_prefix;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;
    pNode->n_prefix = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl->children[index]->n_prefix++;
        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
int search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            return false;

        pCrawl = pCrawl->children[index];
    }

    if (pCrawl != NULL) return pCrawl->n_prefix;
    return 0;
}

// Driver
int main()
{
    // string keys[] = {"the", "a", "there", 
    //                 "answer", "any", "by", 
    //                  "bye", "their" }; 
    // int n = sizeof(keys)/sizeof(keys[0]); 
  
    // struct TrieNode *root = getNode(); 
  
    // // Construct trie 
    // for (int i = 0; i < n; i++) 
    //     insert(root, keys[i]); 
  
    // // Search for different keys
    // cout << search(root, "bye") << endl;
    // cout << search(root, "by") << endl;
    // cout << search(root, "b") << endl;
    // cout << search(root, "c") << endl;

    int n, q;
    cin >> n >> q;
    string key;

    struct TrieNode *root = getNode();

    // Construct trie
    for (int i = 0; i < n; i++) {
        cin >> key;
        insert(root, key);
    }

    for (int i = 0; i < q; i++) {
        cin >> key;
        cout << search(root, key) << endl;
    }

    return 0;
}
