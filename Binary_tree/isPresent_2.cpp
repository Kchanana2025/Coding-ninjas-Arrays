// T(n)=2T(n/2)+c->O(n)
// T(n)=T(n-1)+c->O(n)
// space:O(h)
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;

    bool ans = isNodePresent(root->left, x);
    if (ans == true)
        return true;
    else
    {
        ans = isNodePresent(root->right, x);
        if (ans == true)
        {
            return true;
        }
        else
        {
            if (root->data == x) // base case can be in last as well
                return true;
            else
                return ans;
        }
    }
}