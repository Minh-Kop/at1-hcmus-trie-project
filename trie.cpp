#include "trie.hpp"
#include <iostream>
using namespace std;

TrieNode::TrieNode()
{
    for (unsigned short int i = 0; i < 26; i++)
    {
        child[i] = NULL;
    }
}

bool searchItem(TrieNode* root, string key)
{
    if (!root)
    {
        return false;
    }

    cout << "root ";

    TrieNode* Temp = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!Temp->child[index])
        {
            cout << endl;
            return false;
        }
        Temp = Temp->child[index];
        cout << (char)('a' + index) << " ";
    }

    cout << endl;
    return (Temp != NULL && Temp->End);
}

int countItem(TrieNode* root)
{
    if (isEmpty(root))
    {
        return 0;
    }

    int Count = 0;

    if (root->End)
    {
        Count++;
    }
    for (int i = 0; i < 26; i++)
    {
        Count += countItem(root->child[i]);
    }

    return Count;
}

bool isEmpty(TrieNode* root)
{
    if (!root)
    {
        return true;
    }
    return false;
}

bool isEmptyOfChild(TrieNode* root)
{
    TrieNode* Temp = root;
    for (int i = 0; i < 26; i++)
    {
        if (Temp->child[i])
        {
            return false;
        }
    }
    return true;
}

void insertItem(TrieNode*& root, string key)
{
    for (int i = 0; i < key.size(); i++)
    {
        if (key[i] < 'a')
        {
            key[i] += 32;
        }
    }

    if (isEmpty(root))
    {
        root = new TrieNode;
    }

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

TrieNode* removeItem(TrieNode*& root, string key, int depth)
{
    if (isEmpty(root))
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

        if (isEmptyOfChild(root))
        {
            delete[] root;
            root = NULL;
        }

        return root;
    }

    int index = key[depth] - 'a';
    root->child[index] = removeItem(root->child[index], key, depth + 1);

    if (isEmptyOfChild(root) && !root->End)
    {
        delete[] root;
        root = NULL;
    }

    return root;
}

void removeAll(TrieNode*& root)
{
    if (!root)
    {
        return;
    }

    for (int i = 0; i < 26; i++)
    {
        if (root->child[i])
        {
            removeAll(root->child[i]);
            root->child[i] = NULL;
        }
    }

    delete[] root;
}

TrieNode* buildTrie(TrieNode* root, string file_name)
{
    ifstream input;
    input.open(file_name);
    if (!input.is_open())
    {
        cout << "Can't open the file.\n";
        input.close();
        return NULL;
    }

    int n;
    input >> n;

    string* keys = new string[n];
    for (int i = 0; i < n; i++)
    {
        input >> keys[i];
        insertItem(root, keys[i]);
    }

    delete[] keys;
    input.close();
    return root;
}

void printAllSimilarWords(TrieNode* root, string word)
{
    if (!root)
    {
        return;
    }

    if (root->End)
    {
        cout << word << endl;
    }

    for (int i = 0; i < 26; i++)
    {
        if (root->child[i])
        {
            word.push_back('a' + i);
            printAllSimilarWords(root->child[i], word);
            word.pop_back();
        }
    }
}

void suggestItem(TrieNode* root, string word)
{
    if (!searchItem(root, word))
    {
        cout << "There is no word matched with the dictionary.\n";
        return;
    }

    TrieNode* track = root;
    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';
        track = track->child[index];
    }

    printAllSimilarWords(track, word);
}

void printTrieInorder(TrieNode* root, int letter)
{
    if (root == NULL)
    {
        return;
    }

    bool check = true;
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i])
        {
            printTrieInorder(root->child[i], i);
            if (check)
            {
                if (letter < 0)
                {
                    cout << "root ";
                }
                else
                {
                    cout << (char)('a' + letter) << " ";
                }
                check = false;
            }
        }
    }
    if (check)
    {
        cout << (char)('a' + letter) << " ";
    }
}