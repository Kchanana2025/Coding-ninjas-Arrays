// bss sare alag alag tarike hai ek level pe nodes khtm hojaaane ke baad agle level paar badhne ka
vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> v; // for storing heads of link list
    if (root == NULL)
    {
        v.push_back(NULL); // vector contains only 1 head i.e NULL
        return v;
    }
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    queue<BinaryTreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    int curr = 1;       // no of nodes in current level
    int next_level = 0; // no of nodes in next level
    while (pending_nodes.size() != 0)
    {
        BinaryTreeNode<int> *x = pending_nodes.front();
        pending_nodes.pop();
        Node<int> *newnode = new Node<int>(x->data);
        if (head == NULL && tail == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        if (x->left != NULL) // first method mein toh NULL isloye nai dalna tha kyunki wo level ko disturb krta lekin normally jaise iss case mein daalne ka bhi kya fayeda jo children actually mein hai wohi print hona chahie
        {
            pending_nodes.push(x->left);
            next_level++;
        }
        if (x->right != NULL)
        {
            pending_nodes.push(x->right);
            next_level++;
        }
        curr--;
        if (curr == 0)
        {
            v.push_back(head);
            curr = next_level;
            next_level = 0;
            head = NULL;
            tail = NULL;
        }
    }
    return v;
}