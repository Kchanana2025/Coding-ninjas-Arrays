// O(n)
// O(h)
#include <stdlib.h>                                         //i didnt know about this library
pair<int, int> isBalanced_helper(BinaryTreeNode<int> *root) // this function returns final bool value and height
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = true;
        p.second = 0;
        return p;
    }
    pair<int, int> ans_left = isBalanced_helper(root->left);
    pair<int, int> ans_right = isBalanced_helper(root->right);
    int ansL = ans_left.first;
    int hL = ans_left.second;
    int ansR = ans_right.first;
    int hR = ans_right.second;
    int final_h = 1 + max(hL, hR);
    bool final_ans = false;
    if (ansL == true && ansR == true)
    {
        if (abs(hL - hR) <= 0)
            final_ans = true;
    }

    pair<int, int> p;
    p.first = final_ans;
    p.second = final_h;
    return p;
}
bool isBalanced(BinaryTreeNode<int> *root)
{
    pair<int, int> ans = isBalanced_helper(root);
    return ans.first;
}
