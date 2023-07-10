int length(Node *head)
{
    if (head == NULL)
        return 0;
    Node *temp = head;
    int counter = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        counter++;
    }
    return counter; // i.e length of the link list
}

Node *appendLastNToFirst(Node *head, int n)
{

    int len = length(head);
    int i = len - n; // index of the node from which we wish to start the link list
    // uss phli node ka index jisko uthake hamien shuru mein lana h
    if (head == NULL || i > len - 1 || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    int counter = 0;
    while (temp != NULL && counter < i - 1)
    {
        temp = temp->next;
        counter++;
    }
    Node *new_head = temp->next;
    temp->next = NULL;
    Node *temp1 = new_head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = head;
    head = new_head;
    return head;
}
