#include "Trie.h"
#include <iostream>
using namespace std;
int main()
{
    trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");
    cout << t.search("and") << endl;
    t.removeword("and");
    cout << t.search("and") << endl;
    return 0;
}