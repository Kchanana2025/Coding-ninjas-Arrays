int getLargeNodeCount(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return 0;
    int counter = 0;
    if (root->data > x)
    {
        counter++; // OR counter=1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        counter += getLargeNodeCount(root->children[i], x);
    }
    return counter;
}
