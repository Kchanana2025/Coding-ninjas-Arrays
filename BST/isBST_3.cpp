// O(n)
// O(h)
#include <climits>
bool isBST(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
// jabki function call mein sirf root hai hmne apne aap se default variable bna lie apne use ke lie aise default variables bna skte hain
{
    if (root == NULL)
        return true;
    if (root->data < min || root->data > max)
        return false;

    bool isleftok = isBST(root->left, min, root->data - 1);
    bool isrightok = isBST(root->right, root->data, max);
    return isleftok && isrightok;
}