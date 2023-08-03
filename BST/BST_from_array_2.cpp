

BinaryTreeNode<int> *constructTree(int *input, int n)
{
    // Write your code here
    if (n == 0)
        return NULL;
    int low = 0, high = n - 1, mid = (low + high) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);
    root->left = constructTree(input, mid);
    root->right = constructTree(&input[mid + 1], n - 1 - mid);
    return root;
}