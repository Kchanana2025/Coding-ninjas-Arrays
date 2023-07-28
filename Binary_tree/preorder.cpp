// generic trees mein base case hota hi nai hai
void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL) // base case
        return;
    cout << root->data << " "; // small calculation
    // ye space nai lgaoge toh  sare test case pass nai hoge
    preOrder(root->left); // recursive calls
    preOrder(root->right);
}