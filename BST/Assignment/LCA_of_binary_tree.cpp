// O(n)
// O(n)
int getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    if (root == NULL) // i forgot this
        return -1;

    if (root->data == a || root->data == b) // if root's data is equal to a lets say then is is possible that b exists in tree or not exist in tree in both cases a ie root->data must be returned
    {
        return root->data;
    }
    int ansL = getLCA(root->left, a, b);
    int ansR = getLCA(root->right, a, b);
    if (ansL != -1 && ansR != -1) // that mean a is and b are present in L and R subtrees seperately therefore root->data must be returned
    {
        return root->data;
    }
    else if (ansL == -1 && ansR == -1)
        return -1;
    else if (ansL == -1)
        return ansR;
    else if (ansR == -1)
        return ansL;
}