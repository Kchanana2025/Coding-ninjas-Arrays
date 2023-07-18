void preorder(TreeNode<int> *root)
{
    if (root == NULL) // this is not a base case this is a edge case
        return NULL;
    cout << root->data << " ";
    for (i = 0; i < children.size(); i++)
    {
        preorder(root->children[i]);
    }
}