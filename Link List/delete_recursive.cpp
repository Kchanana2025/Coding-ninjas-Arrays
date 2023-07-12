// O(n)
// O(n)
Node *deleteNodeRec(Node *head, int i)
{
    if (head->next == NULL && i != 0) // mtlb ki aage badhte badhte last node pr aa gye lekin i ya toh negative no hai agee ka no hai therefore head jo tha ussi ko return krdo
        return head;
    if (i == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *temp = deleteNodeRec(head->next, i - 1);
    head->next = temp;
    return head;
}