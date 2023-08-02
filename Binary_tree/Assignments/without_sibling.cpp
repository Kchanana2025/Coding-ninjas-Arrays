// O(n)
// O(h)
void printNodesWithoutSibling(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;
    if (root->left != NULL && root->right == NULL)
        cout << root->left->data << " "; // print wala swal mein hmesha spaces print krni hoti hai mt bhoola kro unko
    else if (root->left == NULL && root->right != NULL)
        cout << root->right->data << " ";
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}