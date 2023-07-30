// dhyan se smjho itne sare else lgane ki koi need hi nai hai if mein ghusa toh bahar aake apne aap false return ho jayega
#include <stdlib.h>
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL) // agar apko ek node ko height 0 rakhna hai toh keep condition like root->left==NULL && root->right==NULL
    {
        return 0;
    }
    return 1 + height(root->left) + height(root->right);
}
bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    int hL = height(root->left);
    int hR = height(root->right);
    if (abs(hL - hR) <= 1) // it is abs not mod
    {
        bool x = isBalanced(root->left);
        if (x == true)
        {
            bool y = isBalanced(root->right);
            if (y == true)
                return true;
        }
    }
    return false;
}