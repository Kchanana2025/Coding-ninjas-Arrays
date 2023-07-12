// Done in leetcode sheet
// Time:O(n/2)//sirf wo wala time dekhenge jab tak fast null nai ho jata aur fast toh n/2 nodes hi visit kr rha hai socho
// slow isliye nai dekh rhe kyunki uss n/2 time mein hi slow bhi aage  chla jayega a toh usse kyu dekhna hai
// Space:O(1)
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {

        // Write your code here
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;                     // agar 1 2 3 4 mein middle ko 2 pe lana ho toh fast ko ek aage se shuru krte hain nai toh head hi
        while (fast != NULL && fast->next != NULL) // and lgega yaad rakhna ye baat
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};