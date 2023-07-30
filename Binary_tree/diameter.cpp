// O(n^2)
// O(h)
#include <iostream>
using namespace std;
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
int diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL) // base case that if root is NULL diameter of binary tree is zero
        return 0;
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    int ans = max(option1, max(option2, option3));
    return ans;
}
