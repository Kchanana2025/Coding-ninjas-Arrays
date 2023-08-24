bool search(TrieNode *root, string word)
{
    // base case
    if (word.size() == 0)
    {
        if (root->isTerminal == true)
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