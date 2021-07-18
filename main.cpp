#include "trie.hpp"
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    int n=0;
    string *keys;
    TrieNode* root = new TrieNode;
    ifstream inp("input.txt");
    buildTrie(root, inp, keys, n);
    inp.close();
    searchItem(root, "the") ? cout << "Yes\n" : cout << "No\n";
    searchItem(root, "their") ? cout << "Yes\n" : cout << "No\n";

    removeItem(root, "heroplane");
    searchItem(root, "heroplan") ? cout << "Yes\n" : cout << "No\n";
    searchItem(root, "heroplane") ? cout << "Yes\n" : cout << "No\n";
    searchItem(root, "her") ? cout << "Yes\n" : cout << "No\n";
    cout << countItem(root) << endl;
    return 0;
}

