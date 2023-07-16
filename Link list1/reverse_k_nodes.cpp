// 1 node aur k=1 se koi ffrak nai padhega isliye base case ni lgaya
// akele k=1 se bhi frak nai padhega
ListNode *getkth(ListNode *current, int k)
{
    while (current && k)
    {
        current = current->next;
        k--;
    }
    return current;
}
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(INT_MIN, head);
        ListNode *group_prev = dummy; // it is basically jis node pe hm operation kr rhe hain usse just phle wale node
        // 1->2->3
        // 1->3->2
        // here address of 1 is required that is taken care by grp previous
        while (1)
        {
            ListNode *kth = getkth(group_prev, k);
            if (!kth) // this is the termination condition
            {
                break;
            }
            ListNode *group_next = kth->next; // just aage wala node or we can say agle grp ka first  node ye hmne isliye save kia hai taki current grp ke first node ko isse jod sakien
            ListNode *previous = group_next;
            //    sbse phle current ko isi se jodna hai isliye previous ko group_next set kia hai
            ListNode *current = group_prev->next;
            ListNode *temp;
            while (current != group_next)
            {
                temp = current->next;
                current->next = previous;
                previous = current;
                current = temp;
            }
            temp = group_prev->next; // kyunki ye groupprev->next jo hai agle group ke lie groupprev bnega isliye iss ko baacha ke rakh lia
            group_prev->next = kth;
            group_prev = temp;
        }
        return dummy->next;
    }
};
