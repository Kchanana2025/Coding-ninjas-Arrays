// O(n)
// O(h)
int helper_replaceWithLargerNodesSum(BinaryTreeNode<int> *root, int sum)
{
    if (root == NULL)
        return sum;

    sum = helper_replaceWithLargerNodesSum(root->right, sum); // sum u send as a parameter acts like abhi tak ka sum
    sum = sum + root->data;
    root->data = sum;
    sum = helper_replaceWithLargerNodesSum(root->left, sum);
    return sum;
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return;
    int sum = 0;
    helper_replaceWithLargerNodesSum(root, sum);
}
