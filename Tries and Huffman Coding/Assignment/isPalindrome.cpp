
// there is a part of code that needs to be completed .Because some test cases are not passing plz check coding ninjas solution for more reference
// O(N*M)
// O(N*M)
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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

    bool add(TrieNode *root, string word)
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
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word)
    {
        if (add(root, word))
        {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */

    // bool isPalindromePair(vector<string> words) {
    //     // Write your code here
    // }
    // bool searchPalindrome(TrieNode *parent, string word) {
    //   if (parent->isTerminal || word.size() == 0)
    //     return true;
    //   if (parent->children[word[0] - 'a'] != NULL)
    //     return searchPalindrome(parent->children[word[0] - 'a'], word.substr(1));
    //   else
    //     return false;
    // }

    // bool searchPalindrome(vector<string> v) {
    //   for (int i = 0; i < v.size(); i++) {
    //     string s1 = v[i], s2 = v[i];
    //     reverse(s1.begin(), s1.end());//s1 ke andar reversed string aa jayegi
    //     if (searchPalindrome(root, s1))
    //       return true;
    //   }
    //   return false;
    // }

    // bool isPalindromePair(vector<string> words) {
    //   // Write your code here
    //   for (int i = 0; i < words.size(); i++)
    //     add(words[i]);
    //   return searchPalindrome(words);
    // }
    bool find_string(TrieNode *root, string s1)
    {
        if (s1.size() == 0 && root->isTerminal == true)
        {
            return true;
        }
        int index = s1[0] - 'a';
        if (root->children[index] != NULL)
        {
            TrieNode *child = root->children[index];
            if (find_string(child, s1.substr(1)) == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    bool check_palindrome_first_condition(vector<string> words)
    {
        // lets first make a trie
        // for (int i = 0; i < words.size(); i++)
        // {
        //     add(words[i]);
        // }
        // now check reverse words in those tries
        for (int i = 0; i < words.size(); i++)
        {
            string s1 = words[i];
            reverse(s1.begin(), s1.end()); // s1 ke andar reversed string aa jayega
            int len = s1.size();
            // we will find reversed sring in trie
            if (find_string(root, s1) == true || find_string(root, s1.substr(1)) == true) // u require root for finding a string in trie
            {
                return true;
            }
        }
        return false;
    }
    bool check_palindrome_second_condition(string s)
    {

        for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

    bool isPalindromePair(vector<string> words)
    {
        if (!root)
        {
            return false;
        }

        // 2nd condition of the question
        for (int i = 0; i < words.size(); i++)
        {
            string s = words[i];

            if (check_palindrome_second_condition(s) == true)
            {
                return true;
            }
        }
        // 1st condition of the question
        // ye function dekhega ki agar ek string ka reverse apko mil jata hai trie mein toh mtlb un dono strings ko jod kr palindrome bhi ban jayega
        return check_palindrome_first_condition(words);
    }
};