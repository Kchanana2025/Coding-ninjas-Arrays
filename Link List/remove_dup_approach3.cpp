
class Solution
{
public:
    Node *deleteDuplicates(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        head->next = deleteDuplicates(head->next);
        return head->data == head->next->data ? head->next : head;
    }
};