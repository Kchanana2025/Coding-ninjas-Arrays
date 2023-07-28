bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    else
    {
        bool ans = isNodePresent(root->left, x);
        if (ans == true)
            return true;
        else
        {
            ans = isNodePresent(root->right, x);
            return ans;
        }
    }
}