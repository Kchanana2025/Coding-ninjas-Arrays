// O(n)
// O(n)
BinaryTreeNode<int> *constructTree_helper(int *input, int si, int ei)
{
    if (si > ei)
    {
        return NULL;
    }
    int mid = (si + ei) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);
    root->left = constructTree_helper(input, si, mid - 1);
    root->right = constructTree_helper(input, mid + 1, ei);
    return root;
}

BinaryTreeNode<int> *constructTree(int *input, int n)
{
    int si = 0;
    int ei = n - 1;
    // BinaryTreeNode<int> *root=constructTree_helper(input, int si=0, int ei=n-1);//calling function like this is not allowed
    BinaryTreeNode<int> *root = constructTree_helper(input, si, ei);
    return root;
}