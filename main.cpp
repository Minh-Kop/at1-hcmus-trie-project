#include <iostream>
#include <string>
#include "trie.hpp"
using namespace std;


int main(int argc, char* argv[])
{
    string input = "D:\\at1-hcmus-trie-project\\words.txt";
    TrieNode* root = new TrieNode;
    buildTrie(root, input);

    cout << "Choice: \n1. Print all trie \n2. Search a word \n3. Search all familar words \n4. Delete a word\n";

    int choice;
    do
    {
        cout << "\nInput your choice: ";
        cin >> choice;
    } while (choice > 4 || choice < 1);

    switch (choice)
    {
    case 1:
    {
        printTrie(root);
        break;
    }
    case 2:
    {
        string word;
        cout << "Input a word that you want to search: ";
        cin >> word;
        if (searchItem(root, word))
        {
            cout << word << " is in the dictionary.\n";
        }
        else
        {
            cout << word << " isn't in the dictionary.\n";
        }
        break;
    }
    case 3:
    {
        string word;
        cout << "Input a word that you want to search all similar words with that word: ";
        cin >> word;
        suggestItem(root, word);
        break;
    }
    case 4:
    {
        string word;
        cout << "Input a word that you want delete: ";
        cin >> word;
        removeItem(root, word);
        if (searchItem(root, word))
        {
            cout << word << " is in the dictionary.\n";
        }
        else
        {
            cout << word << " is no longer in the dictionary.\n";
        }
        break;
    }
    }

    removeAll(root);
    return 0;
}