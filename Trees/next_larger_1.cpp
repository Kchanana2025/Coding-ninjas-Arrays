// O(n)
// O(h)
#include <limits.h>
TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    TreeNode<int> *ans = NULL;
    int min = INT_MAX; // INT_MIN nai hoga soch smjhke lgaya kro
    if (root == NULL)
        return NULL;
    min = root->data - x;
    if (min > 0)
        ans = root;
    else // else lgana bhool gayi thi
        min = INT_MAX;

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *Node = getNextLargerElement(root->children[i], x);
        if (Node != NULL)
        { // agar koi bhi value badi na mile toh NULL return krna hoga ye maine padha nai tha question mein isliye na ans ko null se initialize kia aur na node!=NULL lgaya
            int min_1 = Node->data - x;
            if (min_1 < min)
            {
                min = min_1;
                ans = Node;
            }
        }
    }
    return ans;
}