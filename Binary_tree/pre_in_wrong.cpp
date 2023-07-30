// issue with this code is that ki connections hi bn rhe hai bss tum hr call pe node bnae jaare ho aur uska right aur left bnae jaare ho
BinaryTreeNode<int> *buildtreehelper(int *preOrder, int *inOrder, int preS, int preE, int InS, int InE)
{
    if (InE < InS)
        return NULL;

    int rootindex = -1;
    int rootdata = preOrder[preS];
    for (int i = InS; i <= InE; i++)
    {
        if (rootdata == inOrder[i])
        {
            rootindex = i;
            break;
        }
    }

    int LpreS = preS + 1;
    int LInS = InS;
    int LInE = rootindex - 1;
    int LpreE = LInE - LInS + LpreS;
    int RpreS = LpreE + 1;
    int RInS = rootindex + 1;
    int RInE = InE;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preOrder[preS]);
    BinaryTreeNode<int> *root_L = new BinaryTreeNode<int>(preOrder[LpreS]);
    BinaryTreeNode<int> *root_R = new BinaryTreeNode<int>(preOrder[RpreS]);
    root->left = root_L;
    root->right = root_R;
    BinaryTreeNode<int> *x = buildtreehelper(preOrder, inOrder, LpreS, LpreE, LInS, LInE);
    x = buildtreehelper(preOrder, inOrder, RpreS, RpreE, RInS, RInE);

    return root;
}
BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    return buildtreehelper(preorder, inorder, 0, preLength - 1, 0, inLength - 1);
}