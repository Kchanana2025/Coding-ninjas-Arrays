Node *reverseLinkedListRec(Node *head)
{
    if (head == NULL || head->next == NULL) // BASE CASE
    {
        return head;
    }
    Node *new_head = reverseLinkedListRec(head->next);

    // Node *temp=new_head;//NO need of this loop last node head ka next hi hai,dry run krke dekho
    // while (temp->next != NULL) // until last node is not reached
    // {
    //   temp = temp->next;
    // }
    Node *temp = head->next;
    temp->next = head
                     head->next = NULL;
    head = new_head;
    return head;
}