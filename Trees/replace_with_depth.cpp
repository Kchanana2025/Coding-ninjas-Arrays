// O(n)
// O(h)
void replace_depth(TreeNode<int> *root, int d)
{
    root->data = d;
    d++; // ya phir function parameter mein d+1 bhjdo
    for (int i = 0; i < root->children.size(); i++)
    {
        replace_depth(root->children[i], d);
    }
}
void replaceWithDepthValue(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    int d = 0;
    replace_depth(root, d);
}
