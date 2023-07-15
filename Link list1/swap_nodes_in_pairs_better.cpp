// O(n)
// O(n)
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *temp = swapPairs(head->next->next);
        ListNode *a = head->next;
        head->next = temp;
        // if(a->next!=NULL){
        //     a->next->next=NULL;
        // }
        a->next = head;
        head = a;
        return head;
    }
};