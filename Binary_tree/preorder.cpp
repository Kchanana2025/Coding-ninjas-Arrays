// T(n)=2T(n/2)+O(1)average
// T(n)=2T(n-1)+O(1)worst
// O(n)
// generic trees mein base case hota hi nai hai usme root==NULL wala edge case hota hai
void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL) // base case
        return;
    cout << root->data << " "; // small calculation
    // ye space nai lgaoge toh  sare test case pass nai hoge kyunki space ko bhi consider krta hai wo
    preOrder(root->left); // recursive calls
    preOrder(root->right);
}