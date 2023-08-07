wrong code int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int hL = largestBSTSubtree(root->left);
    int hR = largestBSTSubtree(root->right);
    if (root->left != NULL && root->right != NULL)
    {
        if (root->left->data < root->data && root->data < root->right->data)
        {
            return 1 + max(hL, hR);
        }
    }
    if (root->left != NULL && root->left->data < root->data)
    {
        return 1 + hL;
    }
    if (root->right != NULL && root->data < root->right->data)
    {
        return 1 + hR;
    }
    return max(hL, hR);
}