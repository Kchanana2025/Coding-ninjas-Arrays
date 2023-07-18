int getHeight(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int height = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int x = getHeight(root->children[i]);
        if (x > height)
            height = x;
    }
    return height + 1;
}
//**********************************************************************************************
int getHeight(TreeNode<int> *root)
{
    // Write your code here
}
void getHeight(TreeNode<int> *root, int height, int *max)
{
    if ((*max) < height)
        *max = height;
    for (int i = 0; i < root->children.size(); i++)
        getHeight(root->children[i], 1 + height, max);
}
int getHeight(TreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return 0;
    int max = 1, height = 1;
    getHeight(root, height, &max);
    return max;
}