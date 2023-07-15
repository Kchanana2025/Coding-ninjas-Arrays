// did it from needtcode

// O(n)
// O(1)
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        if (head == NULL && head->next == NULL)
        {
            return head;
        }
        if (k <= 0)
        {
            return head;
        }
        ListNode *temp = head;
        while (k - 1)
        {
            temp = temp->next;
            k--;
        }
        ListNode *left = head;
        ListNode *right = temp;
        while (right->next != NULL)
        {
            left = left->next; // left=right;
            right = right->next;
        }
        swap(left->val, temp->val);
        return head;
    }
};