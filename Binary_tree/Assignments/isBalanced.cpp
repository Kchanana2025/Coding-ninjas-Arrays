#include <stdlib.h> //i didnt know about this library
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
            else
                return false;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    // zaruri nai hai last mein kuch na kuch return kia hi jaye
    //   jab sabhi if else statements mein kuch na kuch return ho rha hai toh mt kro return last mein kuch
}