int getLeafNodeCount(TreeNode<int> *root)
{

    if (root == NULL)
    {
        return 0;
    }
    if (root->children.size() == 0)
        return 1;
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        // cout<<root->children[i]->data<<" ";
        ans = ans + getLeafNodeCount(root->children[i]);
        //   cout<<ans<<" ";
    }
    return ans;
}