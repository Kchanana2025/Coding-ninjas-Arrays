// O(2n)
// O(1)
class Solution
{
public:
    int length(ListNode *head)
    {
        ListNode *temp = head;
        int counter = 0;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    ListNode *swapNodes(ListNode *head, int k)
    {
        if (head == NULL && head->next == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        ListNode *temp1 = NULL;
        ListNode *temp2 = NULL;
        int pos = 1; // indexes start from 1 remember
        int len = length(head);
        while (temp != NULL)
        {
            if (pos == k)
            {
                temp1 = temp;
            }
            if (pos == len - k + 1)
            {
                temp2 = temp;
            }
            temp = temp->next;
            pos++;
        }
        swap(temp1->val, temp2->val);
        return head;
    }
};