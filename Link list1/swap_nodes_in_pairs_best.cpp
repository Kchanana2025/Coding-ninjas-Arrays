// I did from neet code
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL) // do nodes ka hona toh minimum zaruri hai hiw
        {
            return head;
        }
        ListNode *dummy = new ListNode(INT_MIN, head);
        ListNode *previous = dummy; // previous jo hai wo pichle pair ke second node pe betha hai hr iteration mein taki aage pair se sahi se connection ho ske
        ListNode *current = head;   // current hi traverse kr hai poori list mein

        while (current && current->next) // agar current ka next NULL hai mtlb ek node hai tab toh koi swapping krni hi nai hai
        {
            ListNode *second = current->next;         // it is second node in current pair
            ListNode *Nextpair = current->next->next; // it is first node of next pair
            // swap
            second->next = current;
            current->next = Nextpair;
            previous->next = second;

            // traversing
            previous = current; // u might be thinking ki =second hona chahie tha but nai link list change ho chuki hai
            current = Nextpair;
        }
        return dummy->next;
    }
};