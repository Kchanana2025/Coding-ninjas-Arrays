void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL) // agar khali tree hai sirf tab hi zarurat hai iss condition ki0.
        return;

    queue<BinaryTreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pending_nodes.front();
        pending_nodes.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L:" << front->left->data << ",";
            pending_nodes.push(front->left);
        }
        if (front->left == NULL)
        {
            cout << "L:-1,";
        }

        if (front->right != NULL) // if ayega idhar else if nahi
        {
            cout << "R:" << front->right->data;
            pending_nodes.push(front->right);
        }
        if (front->right == NULL)
        {
            cout << "R:-1";
        }
        cout << endl;
    }
}