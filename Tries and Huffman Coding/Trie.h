#include "TrieNode.h"
#include <iostream>
using namespace std;
#include <string>
class trie
{
    TrieNode *root;

public:
    trie()
    {
        root = new TrieNode('\0');
    }
    void insertWord(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            root->isterminal = true;
            return;
        }
        // small calc
        TrieNode *child = NULL;
        int index = word[0] - 'a';         // finding index of word[0] in children array of root, (ascii values of the characters will be subtracted) a will be placed on 0th index ,b on 1st index....
        if (root->children[index] != NULL) // address of letter is present in children array
        {
            child = root->children[index];
        }
        else // address of required letter is not present in children array
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        // recursive call
        insertWord(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertWord(root, word);
    }
    bool search(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            if (root->isterminal = true)
                return true;
            else
                return false;
        }
        // small calc
        TrieNode *child = NULL;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        // recursive call
        return search(child, word.substr(1));
    }
    bool search(string word)
    {
        return search(root, word);
    }
    void removeword(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            // on setting isTerminal as false of terminal node (that word will no longer be a word)
            root->isterminal = false;
            return;
        }
        // small calc
        TrieNode *child = NULL; //(its just a good practice of not leaving pointers with garbage value in them)
        int index = word[0] - 'a';
        if (root->children[index] != NULL) // particular letter exists
        {
            child = root->children[index];
        }
        else
        {
            return; // word is not present so return
        }
        // cantrol will reach here agar if statmenet execute hui hogi
        // agar if execute hui hogi mtlb wo letter ka child present hai therefore recursion must be called
        removeword(child, word.substr(1));
        // delete child if it is useless
        if (child->isterminal == false) // two conditions for a trie node to be deleted
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                    return;
            }
            // agar cantrol yaha aa gya hai mtlb child useless hai
            root->children[index] = NULL;
            delete child;
        }
    }
    void removeword(string word)
    {
        removeword(root, word);
    }
};
