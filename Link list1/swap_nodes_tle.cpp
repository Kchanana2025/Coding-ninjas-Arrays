Node *swapNodes(Node *head, int i, int j)
{

    if (head == NULL)
        return head;
    else if (i == j) // i forgot this test case
        return head;
    //    i>=len-1|| j>=len-1//aisa test case toh hi denge ig
    //    return head;
    Node *temp1 = head;
    Node *temp2 = head;
    int count = 0;
    while (temp1 != NULL && count < i - 1)
    {
        temp1 = temp1->next;
        count++;
    } // after end of this loop temp will be at i-1th posn
    count = 0;
    while (temp2 != NULL && count < j - 1)
    {
        temp2 = temp2->next;
        count++;
    }
    // temp1 is ith node ka prev
    Node *a = temp1->next;
    Node *a_next = a->next;
    // temp2 is jth node ka prev
    Node *b = temp2->next;
    Node *b_next = b->next;
    if (abs(j - i) == 1)
    {
        temp1->next = b;
        b->next = a;
        a->next = b_next;
    }
    else
    {
        temp1->next = b;
        b->next = a_next;
        temp2->next = a;
        a->next = b_next;
    }

    return head;
}