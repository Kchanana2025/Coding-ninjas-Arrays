
#include <limits.h>
class helper_class
{
public:
    int minimum;
    int maximum;
    bool isBST;
    int height;
};
helper_class helper_largestBSTSubtree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        helper_class h;
        h.minimum = INT_MAX;
        h.maximum = INT_MIN;
        h.isBST = false;
        h.height = 0;
        return h;
    }
    if (root->left == NULL && root->right == NULL)
    {
        helper_class h;
        h.minimum = root->data;
        h.maximum = root->data;
        h.isBST = true;
        h.height = 1;
        return h;
    }
    helper_class h1 = helper_largestBSTSubtree(root->left);
    helper_class h2 = helper_largestBSTSubtree(root->right);
    helper_class h;

    if (root->left != NULL && root->right != NULL)
    {
        if (h1.maximum < root->data && root->data < h2.minimum && h1.isBST && h2.isBST)
        {
            h.minimum = h1.minimum;
            h.maximum = h2.maximum;
            h.height = 1 + max(h1.height, h2.height);
            h.isBST = true;
            return h;
        }
    }
    if (root->left != NULL)
    {
        if (h1.maximum < root->data && h1.isBST)
        {
            h.isBST = true;
            h.height = h1.height + 1;
            h.minimum = h1.minimum;
            h.maximum = root->data;
            return h;
        }
    }
    if (root->right != NULL)
    {
        if (h2.minimum > root->data && h2.isBST)
        {
            h.isBST = true;
            h.height = h2.height + 1;
            h.minimum = root->data;
            h.maximum = h2.maximum;
            return h;
        }
    }
}
int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    helper_class h = helper_largestBSTSubtree(root);
    return h.height;
}