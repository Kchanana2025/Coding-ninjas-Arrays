
void postOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL) // base case
        return;
    postOrder(root->left); // recursive calls
    postOrder(root->right);
    cout << root->data << " "; // small calculation
}
