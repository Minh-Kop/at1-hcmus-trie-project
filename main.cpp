#include "trie.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    string suggest;
    cout << "Search: ";
    cin >> suggest;
    ifstream wordlist("words.txt");
    TrieNode *a = new TrieNode;
    buildTrie(a,wordlist);
    sugestItem(a,suggest);
    removeAll(a);
    return 0;
}

