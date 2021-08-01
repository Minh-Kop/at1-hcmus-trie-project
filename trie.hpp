#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct TrieNode
{
    TrieNode* child[26];
    bool End = false;
    TrieNode();
};

bool searchItem(TrieNode* root, string key);
int countItem(TrieNode* root);
bool isEmpty(TrieNode* root);
void insertItem(TrieNode*& root, string key);
TrieNode* removeItem(TrieNode*& root, string key, int depth = 0);
void removeAll(TrieNode*& root);
TrieNode* buildTrie(TrieNode* root, string file_name);
void printTrieInorder(TrieNode* root, int letter = -1);
void printAllSimilarWords(TrieNode* root, string word);
void suggestItem(TrieNode* root, string word);
