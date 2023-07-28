void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL) // base case
        return;
    swap(root->left, root->right); // small calculation

    mirrorBinaryTree(root->left); // recursive calls
    mirrorBinaryTree(root->right);
}
//*****************************************************/
void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL) // base case
        return;

    mirrorBinaryTree(root->left); // recursive calls
    mirrorBinaryTree(root->right);
    swap(root->left, root->right); // small calculation
}