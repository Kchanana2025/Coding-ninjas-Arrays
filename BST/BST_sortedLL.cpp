// O(n)
// O(h)//link list ko space mein consider nai krte because it is used to store answer it is not used to calculate answer
// this function will return a pair in which head first will have head and ssecond will have tail
pair<Node<int> *, Node<int> *> constructLinkedList_helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<Node<int> *, Node<int> *> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    pair<Node<int> *, Node<int> *> left_data = constructLinkedList_helper(root->left);
    Node<int> *head = new Node<int>(root->data);
    Node<int> *tail = head;
    Node<int> *new_head = head;
    Node<int> *new_tail = tail;

    if (left_data.second != NULL) // this case is very important because it can be NULL
    {
        left_data.second->next = head;
        new_head = left_data.first;
    }

    pair<Node<int> *, Node<int> *> right_data = constructLinkedList_helper(root->right);
    if (right_data.first != NULL) // this case is very important because it can be NULL
    {
        head->next = right_data.first;
        new_tail = right_data.second;
    }

    pair<Node<int> *, Node<int> *> p;
    p.first = new_head;
    p.second = new_tail;
    return p;
}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    pair<Node<int> *, Node<int> *> p = constructLinkedList_helper(root);
    return p.first;
}