void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;
    BinaryTreeNode<int> *node = root;
    int sum = 0;
    while (node != NULL)
    {
        sum += node->data;
        node = node->right;
    }
    root->data = sum;
    replaceWithLargerNodesSum(root->left);
    replaceWithLargerNodesSum(root->right);
}