#include "trie.hpp"
using namespace std;

TrieNode::TrieNode()
{
    for (unsigned short int i = 0; i < 26; i++)
    {
        child[i] = NULL;
    }
}

bool searchItem(TrieNode *Root, string Key)
{
    TrieNode *Temp = Root;

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

int countItem(TrieNode *Root)
{
    int Count = 0;
    if (!Root)
        return 0;
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

bool isEmpty(TrieNode *Root)
{
    if (!Root)
        return 0;
    TrieNode *Temp = Root;
    for (int i = 0; i < 26; i++)
    {
        if (Temp->child[i])
        {
            return false;
        }
    }
    return true;
}

void insertItem(TrieNode *root, string key)
{
    TrieNode *track = root;

    for (int i = 0; i < key.size(); i++)
    {
        int index = key[i] - 'a';
        if (!track->child[index])
        {
            TrieNode *temp = new TrieNode;
            track->child[index] = temp;
        }
        track = track->child[index];
    }

    track->End = true;
}

TrieNode *removeItem(TrieNode *&root, string key, int depth)
{
    if (!root)
    {
        return NULL;
    }

    if (!depth)
    {
        for (int i = 0; i < key.size(); i++)
        {
            if (key[i] < 'a')
            {
                key[i] += 32;
            }
        }
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

void removeAll(TrieNode *&root)
{
    if (!root)
        return;
    for (int i = 0; i < 26; i++)
        if (root->child[i])
        {
            removeAll(root->child[i]);
            root->child[i] = NULL;
        }
    delete[] root;
}

TrieNode *buildTrie(TrieNode *root, istream &input)
{
    int n = 0;
    input >> n;
    string *keys = new string[n];
    for (int i = 0; i < n; i++)
    {
        input >> keys[i];
        insertItem(root, keys[i]);
    }
    delete[] keys;
    return root;
}

void printTrie(TrieNode *root, ostream &output, string word)
{
    if (!root)
        return;
    if (root->End)
        output << word << endl;
    for (int i = 0; i < 26; i++)
        if (root->child[i])
        {
            word.push_back('a' + i);
            printTrie(root->child[i], output, word);
            word.pop_back();
        }
}

void sugestItem(TrieNode *root,string word,ostream &output)
{
    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        if (!root->child[index])
        {
            cout << "There is no word matched with the dictionary";
            return;
        }
        root = root->child[index];
    }
    printTrie(root,output,word);
}