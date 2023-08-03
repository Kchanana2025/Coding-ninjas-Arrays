// O(n*h)
// O(h)
int maximum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MIN;

    int max_val = (root->data, max(maximum(root->left), maximum(root->right)));
    return max_val;
}
int minimum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return INT_MAX;

    int min_val = (root->data, min(minimum(root->left), minimum(root->right)));
    return min_val;
}
bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL) // dry run krke dekho base case mein true hi return hoga
        return true;
    int max_no = maximum(root->left);
    int min_no = minimum(root->right);
    bool output = (max_no < root->data && root->data <= min_no && isBST(root->left) && isBST(root->right));
    return output;
}