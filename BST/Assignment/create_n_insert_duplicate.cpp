// O(n) sabhi nodes ko traverse kia h na ek extra lgane ke lie
// O(h)
void insertDuplicateNode(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *temp = root->left;
    root->left = newnode;
    newnode->left = temp;
    insertDuplicateNode(newnode->left);
    insertDuplicateNode(root->right);
}