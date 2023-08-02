vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> v = {NULL};
    if (root == NULL)
        return v;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        int n = pendingNodes.size();
        Node<int> *head = NULL;
        Node<int> *tail = NULL;
        while (n != 0)
        {
            BinaryTreeNode<int> *front = pendingNodes.front();
            pendingNodes.pop();
            Node<int> *newNode = new Node<int>(front->data);
            if (head == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            if (front->left != NULL)
                pendingNodes.push(front->left);
            if (front->right != NULL)
                pendingNodes.push(front->right);
            n--;
        }
        v.push_back(head);
    }
    return v;
}