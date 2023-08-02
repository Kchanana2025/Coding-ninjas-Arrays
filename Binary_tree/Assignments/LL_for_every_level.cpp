
// time://O(n)// sabhi nodes pr k hi work hua hai so O(n)
// space:O(n+h) n/2 due to queue and h due to vector
vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
    {
        vector<Node<int> *> v;
        v.push_back(NULL);
        return v;
    }
    vector<Node<int> *> v;
    queue<BinaryTreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    pending_nodes.push(NULL);
    while (pending_nodes.size() != 0)
    {
        Node<int> *head = NULL; // before going to any level head and tail must be set to NULL
        Node<int> *tail = NULL;
        while (pending_nodes.front() != NULL)
        {
            BinaryTreeNode<int> *helper = pending_nodes.front(); // we took the node
            pending_nodes.pop();                                 // removed that node
            Node<int> *newnode = new Node<int>(helper->data);    // created a link list
            if (head == NULL && tail == NULL)
            {
                head = newnode;
                tail = newnode;
            }
            else
            {
                tail->next = newnode;
                tail = tail->next;
            }
            if (helper->left != NULL) // I wrote root here instead of helper
                pending_nodes.push(helper->left);

            if (helper->right != NULL)
                pending_nodes.push(helper->right);
        }
        // since one level is completed cantrol comes out of loop
        v.push_back(head);
        pending_nodes.pop();
        if (pending_nodes.size() == 0)
            break;
        pending_nodes.push(NULL); // since one level is completed and this level's children are present in the queue we must put NULL after it
    }
    return v;
}