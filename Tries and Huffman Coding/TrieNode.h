#include <iostream>
using namespace std;
class TrieNode
{
public:
    char data;
    TrieNode **children; // this will store children of every node
    bool isterminal;
    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) // garbage addresses kabhi nai chorne chahie.NULL krdo unhe iss se bdia
        {
            children[i] = NULL;
        }
        isterminal = false;
    }
};