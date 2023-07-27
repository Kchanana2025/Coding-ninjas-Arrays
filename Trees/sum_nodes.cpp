// O(n)
// O(h)
int sum_nodes(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sum_nodes(root->children[i]);
    }
    return sum;
}