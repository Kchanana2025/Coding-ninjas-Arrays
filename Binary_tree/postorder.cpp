// T(n)=2T(n/2)+O(1)average
// T(n)=2T(n-1)+O(1)worst
// O(n)
void postOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL) // base case
        return;
    postOrder(root->left); // recursive calls
    postOrder(root->right);
    cout << root->data << " "; // small calculation
}
