// O(n)
//  O(h)

int getSum(BinaryTreeNode<int> *root)
{

    int sum = 0;
    if (root == NULL) // base case
        return 0;
    sum = root->data;
    int left_ans = getSum(root->left);
    int right_ans = getSum(root->right);
    int final = sum + left_ans + right_ans;
    return final;
}
