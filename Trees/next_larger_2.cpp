// O(n)
// O(h)
TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    TreeNode<int> *Node = NULL;
    if (root == NULL)
        return NULL;
    TreeNode<int> *ans = NULL;
    if (root->data > x)
    {
        // int min=root->data-x;
        ans = root;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        Node = getNextLargerElement(root->children[i], x);
        if (Node != NULL)
        {
            if (ans != NULL && Node->data < ans->data)
                ans = Node;
        }
        if (ans == NULL)
            return Node;
    }
    return ans;
}