// O(N*M)
// O(N*M)
bool searchWord(TrieNode *root, string pattern)
{
    // we will search pattern and and will not take care about isTerminal
    if (pattern.size() == 0)
        return true;
    int index = pattern[0] - 'a';
    TrieNode *child;
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }
    return searchWord(child, pattern.substr(1));
}
bool patternMatching(vector<string> vect, string pattern)
{
    Trie suffix;
    // lets insert words in  Trie
    for (int i = 0; i < vect.size(); i++)
    {
        string word = vect[i];
        for (int j = 0; j < word.size(); j++)
        {
            suffix.insertWord(word.substr(j));
        }
    }
    // lets match pattern now
    return searchWord(suffix.root, pattern);
}