// T(n)=T(n/2)+c->O(n)
// T(n)=T(n-1)+c->O(n)
// space:O(h)
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