int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int lefth = height(root->left);
    int righth = height(root->right);
    if (lefth > righth)
        return 1 + lefth;
    else
        return 1 + righth;
}
