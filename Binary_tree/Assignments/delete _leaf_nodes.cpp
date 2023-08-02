// O(n)
// O(h)
BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    //     if (root == NULL || (root->left == NULL && root->right == NULL)) {
    //     free(root);
    //     return NULL;
    //   }
    // akela ye bhi likh skte thee lekin jaise kia hua maine usme base case aur small calculation kaffi alag alag dikh rhe hain
    if (root == NULL)
    {
        return root;
    }
    if (root->left == NULL && root->right == NULL) // condition for leaf node of a binary tree
    {
        delete root;
        root = NULL;
        return root;
    }
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
}