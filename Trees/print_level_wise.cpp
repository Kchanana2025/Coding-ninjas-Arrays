// whats the difference?
// last children ke baad , nai prrint hoga ye difference hai bus
void printLevelWise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        TreeNode<int> *front = pending_nodes.front(); // we accessed first node inside queue
        pending_nodes.pop();                          // node delete kari queue se
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            if (i == front->children.size() - 1)
            {
                cout << front->children[i]->data;
            }
            else
            {
                cout << front->children[i]->data << ",";
            }
            pending_nodes.push(front->children[i]);
        }
        cout << endl;
    }
}