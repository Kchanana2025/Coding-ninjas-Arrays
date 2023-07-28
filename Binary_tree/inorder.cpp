// generic trees mein base case hota hi nai hai
void InOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL) // base case
        return;
    InOrder(root->left);       // recursive call
    cout << root->data << " "; // small calculation
    InOrder(root->right);      // recursive call
}