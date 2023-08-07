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
        obj.isBST = false;
        obj.height = 0;
        return obj;
    }
    if (root->left == NULL && root->right == NULL)
    {
        helper_class obj;
        obj.minimum = root->data;
        obj.maximum = root->data;
        obj.isBST = true;
        obj.height = 1;
        return obj;
    }
    helper_class ansL = helper_largestBSTSubtree(root->left);
    helper_class ans_R = helper_largestBSTSubtree(root->right);
    helper_class obj;

    if (root->left != NULL && root->right != NULL)
    {
        if (ansL.maximum < root->data && root->data < ans_R.minimum && ansL.isBST && ans_R.isBST)
        {
            obj.minimum = ansL.minimum;
            obj.maximum = ans_R.maximum;
            obj.height = 1 + max(ansL.height, ans_R.height);
            obj.isBST = true;
            return obj;
        }
    }
    if (root->left != NULL)
    {
        if (ansL.maximum < root->data && ansL.isBST)
        {
            obj.isBST = true;
            obj.height = ansL.height + 1;
            obj.minimum = ansL.minimum;
            obj.maximum = root->data;
            return obj;
        }
    }
    if (root->right != NULL)
    {
        if (ans_R.minimum > root->data && ans_R.isBST)
        {
            obj.isBST = true;
            obj.height = ans_R.height + 1;
            obj.minimum = root->data;
            obj.maximum = ans_R.maximum;
            return obj;
        }
    }
    if (ansL.height && ans_R.height)
    {
        helper_class obj;
        if (ansL.height > ans_R.height)
        {
            obj.minimum = ansL.minimum;
            obj.maximum = ansL.maximum;
            obj.isBST = true;
            obj.height = ansL.height;
            return obj;
        }
        else if (ansL.height < ans_R.height)
        {
            obj.minimum = ans_R.minimum;
            obj.maximum = ans_R.maximum;
            obj.isBST = true;
            obj.height = ans_R.height;
            return obj;
        }
    }
    if (ansL.height)
    {
        obj.minimum = ansL.minimum;
        obj.maximum = ansL.maximum;
        obj.isBST = true;
        obj.height = ansL.height;
        return obj;
    }
    if (ans_R.height)
    {
        obj.minimum = ans_R.minimum;
        obj.maximum = ans_R.maximum;
        obj.isBST = true;
        obj.height = ans_R.height;
        return obj;
    }
}
int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    helper_class obj = helper_largestBSTSubtree(root);
    return obj.height;
}
