TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    if (root == NULL)
        return root;
    TreeNode<int> *final = root;
    int sum = root->data; // it will store sum of data of root node and its children
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *Node = maxSumNode(root->children[i]); // Node will be max sum node among the nodes below root
        int sum_2 = Node->data;                              // dont forget to initialize sum_2 with node's data
        for (int i = 0; i < Node->children.size(); i++)      // maine iss loop ko for ke bahar bna dia tha which is wrong aur ye wrong hai ye baat apko dry run krke hi pta chalegi
        {
            sum_2 += Node->children[i]->data;
        }
        if (sum < sum_2)
        {
            sum = sum_2;
            final = Node;
        }
    }
    // now we need to campare root and node
    return final;
}
