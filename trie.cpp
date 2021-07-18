#include "trie.hpp"
#include <fstream>
using namespace std;

TrieNode::TrieNode()
{
    for (unsigned short int i = 0; i < 26; i++)
    {
        child[i] = NULL;
    }
}

bool searchItem(TrieNode* Root, string Key)
{
    TrieNode* Temp = Root;

    for (int i = 0; i < Key.length(); i++)
    {
        int index = Key[i] - 'a';
        if (!Temp->child[index])
        {
            return false;
        }
        Temp = Temp->child[index];
    }

    return (Temp->End);
}

int countItem(TrieNode* Root)
{
    int Count = 0;

    if (Root->End)
    {
        Count++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (Root->child[i])
        {
            Count += countItem(Root->child[i]);
        }
    }

    return Count;
}

bool isEmpty(TrieNode* Root)
{
    TrieNode* Temp = Root;
    for (int i = 0; i < 26; i++)
    {
        if (Temp->child[i])
        {
            return false;
        }
    }
    return true;
}

void insertItem(TrieNode* root, string key)
{
    TrieNode* track = root;

    for (int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';
        if (!track->child[index])
        {
            TrieNode* temp = new TrieNode;
            track->child[index] = temp;
        }
        track = track->child[index];
    }

    track->End = true;
}

TrieNode* removeItem(TrieNode* &root, string key, int depth)
{
    if (!root)
    {
        return NULL;
    }

    if (depth == key.size())
    {
        if (root->End)
        {
            root->End = false;
        }

        if (isEmpty(root))
        {
            delete[] root;
            root = NULL;
        }

        return root;
    }

    int index = key[depth] - 'a';
    root->child[index] = removeItem(root->child[index], key, depth + 1);

    if (isEmpty(root) && !root->End)
    {
        delete[] root;
        root = NULL;
    }

    return root;
}

TrieNode* removeAll(TrieNode *&root,string a[],int n){
    while(!isEmpty(root)){
        for(int i = 0; i < n; i++){
            removeItem(root,a[i]);
        }
        /*for (unsigned short int i = 0; i < 26; i++) {
            root->child[i] = NULL;
        }*/
    }
    return root;
}
TrieNode* buildTrie(TrieNode* root,istream &input, string *&keys, int &n){
    input >> n;
    keys = new string[n];
    for (int i = 0; i < n; i++){
        input >> keys[i];
        insertItem(root, keys[i]);
    }
    return root;
}
