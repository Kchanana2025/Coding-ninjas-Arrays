int length(Node *head) // jo question recursion se ho skta hai usko recursion se kro
{
    if (head == NULL)
        return 0;
    return 1 + length(head->next);
}
Node *appendLastNToFirst(Node *head, int n)
{
    if (head == NULL || n == 0 || head->next == NULL || n > length(head))
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head;
    for (int i = 0; i < n; i++)
    { // jitni nodes peeche se chorni thi utni aage se chordi
        fast = fast->next;
    }
    while (fast->next !=
           NULL) // Dry run krke dekho ab aap fast ko utna aage badha rhe ho such
                 // that link list end ho jaye aur slow bhi utna aage badhe toh
                 // jab slow kochalane lge the tab bhi slow fast mein n nodee ka
                 // difference that jab fast last mein pahuch gya tab bhi n nodes
                 // ka difference hai toh fir finally slow uss nodes ki traf point
                 // kr rha hai jiske next mein hamien null dalna hai
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *new_head = slow->next;
    slow->next = NULL;
    fast->next = head;
    head = new_head;
    return head;
}
