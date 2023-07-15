//  O(2n)
//  O(n)
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        if (head == NULL && head->next == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        int arr[1000000];
        int i = 1;
        while (temp != NULL)
        {
            arr[i] = (temp->val);
            i++;
            temp = temp->next;
        }
        int size = i - 1;
        swap(arr[k], arr[size - k + 1]);
        temp = head;
        i = 1;
        while (temp != NULL)
        {
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }

        return head;
    }
};