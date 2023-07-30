// average:T(n)=2T(n/2)+c->O(n)
// worst:T(n)=T(n-1)+c->O(n)
// space:O(h)
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
