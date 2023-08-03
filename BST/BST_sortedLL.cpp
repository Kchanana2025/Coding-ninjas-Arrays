// O(n)
// O(n)
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

    if (left_data.second != NULL)
    {
        left_data.second->next = head;
        new_head = left_data.first;
    }

    pair<Node<int> *, Node<int> *> right_data = constructLinkedList_helper(root->right);
    if (right_data.first != NULL)
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