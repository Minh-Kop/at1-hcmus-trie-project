#include "trie.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    ifstream wordlist("words.txt");
    TrieNode *a = new TrieNode;
    buildTrie(a,wordlist);
    cout << countItem(a);
    removeAll(a);
    return 0;
}

