BinaryTreeNode<int> *buildtreehelper(int *preOrder, int *inOrder, int preS, int preE, int InS, int InE)
{
    if (InE < InS) // base case
        return NULL;
    // small calculation
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
    // these are all indexes we are calculating so that recursion can calculate left and right subtree for us
    // left/right subtree ke preorder wale indexes preorder traversal se hi niklenge (mostly)
    // left/right subtree ke inorder wale indexes inorder traversal se hi niklenge (mostly)
    // apko ye indexes apne hisab se likhne hain toh zrur likho
    int LpreS = preS + 1;
    int LInS = InS;
    int LInE = rootindex - 1;
    int LpreE = LInE - LInS + LpreS; // asLpreE-LpreS=LinE-LinS
    int RpreS = LpreE + 1;           // dekho zara inorder mein rootindex tak left subtree aur root include ho chuka hai uske just aage jo element hoga will be right subree ka preorde start no inorder ka start hoga preorder ka start ho bhi skta hai nai bhi lekin LpreE+1 definatletly right subtree ka preS hoga
    int RpreE = preE;
    int RInS = rootindex + 1;
    int RInE = InE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preOrder[preS]);
    root->left = buildtreehelper(preOrder, inOrder, LpreS, LpreE, LInS, LInE);
    root->right = buildtreehelper(preOrder, inOrder, RpreS, RpreE, RInS, RInE);

    return root;
}
// this function will return root the the tree that will be build but for that we create a helper function
BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    return buildtreehelper(preorder, inorder, 0, preLength - 1, 0, inLength - 1);
}