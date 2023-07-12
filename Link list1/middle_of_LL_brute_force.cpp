// O(3n/2)=O(n)
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
            temp = temp->next;
            counter++;
        }
        return counter;
    }
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        int x = length(head);
        int mid = x / 2;
        ListNode *temp = head;
        while (mid)
        {
            temp = temp->next;
            mid--;
        }
        return temp;
    }
};