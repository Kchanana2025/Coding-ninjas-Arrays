//  average case:T(n)=2*T(n/2)+kn; O(nlogn)
// worst case: T(n)=2*T(n-1)+kn;O(n^2)
BinaryTreeNode<int> *buildTree(int *postorder, int postLength, int *inorder,
                               int inLength)
{
    // Write your code here
    int rootData = postorder[postLength - 1];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    // base case
    if (postLength == 1)
    {
        return root;
    }
    else if (postLength == 0)
    {
        return NULL;
    }

    int rootIndex = 0;

    while (inorder[rootIndex] != rootData)
    {
        rootIndex++;
    }

    int leftLength = rootIndex;
    int rightLength = inLength - rootIndex - 1;

    root->left = buildTree(postorder, leftLength, inorder, leftLength);
    root->right = buildTree(postorder + leftLength, rightLength, inorder + rootIndex + 1, rightLength); // postorder+leftlength +1 nai kia because postorder ke array mein root is at last toh usko skip kru karoge bhai?

    return root;
}