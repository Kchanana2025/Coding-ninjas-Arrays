// T(n)=2T(n/2)+O(1)average
// T(n)=2T(n-1)+O(1)worst
// O(n)
// space:O(h)
// generic trees mein base case hota hi nai hai.root==NULL is edge case in case of generic trees
void InOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL) // base case
        return;
    InOrder(root->left);       // recursive call
    cout << root->data << " "; // small calculation
    InOrder(root->right);      // recursive call
}