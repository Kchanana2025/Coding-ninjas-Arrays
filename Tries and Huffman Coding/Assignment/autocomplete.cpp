// O(N*M)
// O(N*M)
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        if (insertWord(root, word))
        {
            this->count++;
        }
    }
    void print(TrieNode *root, string solution)
    {
        // cout << root->data;
        if (root == NULL)
            return;

        if (root->isTerminal == true)
        {
            cout << solution << endl;
        }

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                string s = solution + root->children[i]->data; // solution+ nai kr skte dry run krke dekh lo
                print(root->children[i], s);
            }
        }
    }
    void search(TrieNode *root, string pattern, string solution)
    {
        if (pattern.size() == 0)
        {
            print(root, solution);
        }

        int index = pattern[0] - 'a';
        if (root->children[index] != NULL)
        {
            solution += root->children[index]->data;
            search(root->children[index], pattern.substr(1), solution);
        }
    }

    void autoComplete(vector<string> input, string pattern)
    {
        // Write your code here
        // Trie output;
        // firstly populate taht trie with given words
        for (int i = 0; i < input.size(); i++)
        {
            insertWord(input[i]);
        }

        string solution = ""; // ye string isliye bheja hai hai because final solution mein eg pattern no hai toh no bhi print hoga aur aage ke different different outputs bhi
        search(root, pattern, solution);
    }
};