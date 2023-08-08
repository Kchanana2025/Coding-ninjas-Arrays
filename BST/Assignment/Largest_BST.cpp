// O(n)
// O(h)
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
        helper_class obj;
        obj.minimum = INT_MAX;
        obj.maximum = INT_MIN;
        obj.isBST = true;
        obj.height = 0;
        return obj;
    }
    helper_class ansL = helper_largestBSTSubtree(root->left);
    helper_class ans_R = helper_largestBSTSubtree(root->right);
    helper_class obj;

    if (ansL.maximum < root->data && root->data < ans_R.minimum && ansL.isBST && ans_R.isBST)
    {

        obj.minimum = min(ansL.minimum, root->data);
        obj.maximum = max(ans_R.maximum, root->data);
        obj.height = 1 + max(ansL.height, ans_R.height);

        obj.isBST = true;
        return obj;
    }

    else
    {
        obj.minimum = min(root->data, min(ansL.minimum, ans_R.minimum));
        obj.maximum = max(root->data, max(ansL.maximum, ans_R.maximum));
        obj.height = max(ansL.height, ans_R.height);

        obj.isBST = false;
        return obj;
    }
}
int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    helper_class obj = helper_largestBSTSubtree(root);
    return obj.height;
}
