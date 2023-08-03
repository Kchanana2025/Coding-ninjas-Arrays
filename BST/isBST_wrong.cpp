// 2 test cases are not passing.check in notebook why?
bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->left != NULL)
    {
        if (root->left->data > root->data)
        {
            return false;
        }
    }
    if (root->right != NULL)
    {
        if (root->right->data < root->data)
        {
            return false;
        }
    }
    bool x = isBST(root->left);
    if (x == true)
    {
        bool y = isBST(root->right);
        return y;
    }
    return false;
}
