// O(h)
// O(h)

int getLCA(BinaryTreeNode<int> *root, int val1, int val2)
{
    // Write your code here
    if (root == NULL)
        return -1;

    if (root->data == val1 || root->data == val2)
    {
        return root->data;
    }

    if (val1 < root->data && val2 < root->data)
    {
        return getLCA(root->left, val1, val2);
    }
    else if (val1 > root->data && val2 > root->data)
    {
        return getLCA(root->right, val1, val2);
    }
    // cantrol would have come over here only if val1 and val2 are in left /right subtrees or right/left subtrees
    int L = getLCA(root->left, val1, val2);
    int R = getLCA(root->right, val1, val2);
    if (L = -1 && R == -1)
        return -1;
    if (L != -1 && R != -1)
        return root->data;
    if (L == -1)
        return R;
    if (R == -1)
        return L;
}