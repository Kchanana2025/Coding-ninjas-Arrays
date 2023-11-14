Node *reverse(Node *head)
{
    Node *previous = head;
    Node *curr = head->next;
    while (curr != Null)
    {
        Node *helper = curr->next;
        curr->next = previous;
        if (previous == head)
        {
            previous->next = NULL;
        }
        prev = curr;
        curr = helper;
        helper = helper->next;
    }
}