bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x) // else if bhi lga skte thee
        return true;
    return isNodePresent(root->left, x) || isNodePresent(root->right, x);
}