// hm length nikalke uska middle nikale bhi swal kr skte hain
Node *calculate_mid(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reverseLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    { // wese head->next==NULL waali condition na bhi daalien toh bhi neeche wala code 1 node ko dhang se handle kr lega
        return head;
    }
    Node *previous = head;
    Node *curr = head->next;
    while (curr != NULL)
    {
        Node *helper = curr->next;
        curr->next = previous;
        if (previous == head)
        {
            previous->next = NULL;
        }
        previous = curr;
        curr = helper;
        if (helper != NULL)
        {
            helper = helper->next;
        }
    }
    head = previous;
    return previous;
}

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    Node *temp = calculate_mid(head);
    Node *second_head = temp->next;
    temp->next = NULL;
    second_head = reverseLinkedList(second_head);
    //    cout<<second_head->data;
    Node *head1 = head;
    Node *second_head1 = second_head;

    while (head1 && second_head1)
    {
        if (head1->data != second_head1->data)
        {
            return false;
        }

        head1 = head1->next;
        second_head1 = second_head1->next;
    }
    return true;
}
