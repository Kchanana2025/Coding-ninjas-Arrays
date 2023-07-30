// average:T(n)=2T(n/2)+c->O(n)
// worst:T(n)=T(n-1)+c->O(n)
// space:O(h)
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
