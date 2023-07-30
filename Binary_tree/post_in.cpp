//  average case:T(n)=2*T(n/2)+kn; O(nlogn)
// worst case: T(n)=2*T(n-1)+kn;O(n^2)
BinaryTreeNode<int> *buildbinarytree(int *postorder, int postS, int postE, int *inorder, int inS, int inE)
{
    if (inS > inE)
        return NULL;
    int rootdata = postorder[postE];
    int rootindex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (rootdata == inorder[i])
        {
            rootindex = i;
            break;
        }
    }
    int LpostS = postS;
    int LinS = inS;
    int LinE = rootindex - 1;
    int LpostE = LpostS + LinE - LinS;
    int RpostS = LpostE + 1;
    int RpostE = postE - 1;
    int RinS = rootindex + 1;
    int RinE = inE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    root->left = buildbinarytree(postorder, LpostS, LpostE, inorder, LinS, LinE);
    root->right = buildbinarytree(postorder, RpostS, RpostE, inorder, RinS, RinE);
    return root;
}
BinaryTreeNode<int> *buildTree(int *postorder, int postLength, int *inorder, int inLength)
{
    return buildbinarytree(postorder, 0, postLength - 1, inorder, 0, inLength - 1);
}
