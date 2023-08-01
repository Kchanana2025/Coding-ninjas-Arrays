// dry run the code u will get a clarity
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    pending_nodes.push(NULL);
    while (pending_nodes.size() != 0)
    {
        while (pending_nodes.front() != NULL)
        {
            BinaryTreeNode<int> *x = pending_nodes.front();
            pending_nodes.pop();
            cout << x->data << " ";
            if (x->left != NULL)
                pending_nodes.push(x->left);
            if (x->right != NULL)
                pending_nodes.push(x->right);
        }
        pending_nodes.pop();
        if (pending_nodes.size() == 0) // means all nodes have been traversed and there no need to push null now
            break;                     // or continue
        else
        {
            cout << endl;
            pending_nodes.push(NULL);
        }
    }
}