Node *removeDuplicates(Node *head)
{
    if (head == NULL || head->next == NULL)
        // in cases of 0 nodes or 1 node there
        // is no point of removing duplicates
        // hm aise test cases lgate hain taki segmentation fault na aaye
        // becauseNULL-> will cause segmentation fault
        return head;

    int flag = 0;
    Node *temp = head->next;
    Node *previous = head;
    while (temp != NULL)
    {
        if (previous->data == temp->data)
        {
            Node *a = temp;
            previous->next = temp->next;
            temp = temp->next;
            delete a;
        }
        else
        {
            previous = temp;
            temp = temp->next;
        }
    }

    return head; // hmara head badal nai rha bss node*  return type hai bss isiliye return kr rhe
}