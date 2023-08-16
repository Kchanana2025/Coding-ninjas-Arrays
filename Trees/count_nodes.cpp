// O(n)
// O(h)
int count_nodes(TreeNode<int> *root) // bss root wala kaam aap krdo baki recursion sambhal lega
{
    if (root == NULL)
        return 0;

    int counter = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        counter += count_nodes(root->children[i])
    }
    return counter;
}