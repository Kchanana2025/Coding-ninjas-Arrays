// O(n)
// O(1)
#include <limits.h>
Node *evenAfterOdd(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // dummy node bna lia kro beneficial rehta hai edge cases ke point of view se
    // ab fayeda ye hai ki hm seedha temp1 ya temp2 ke next mein saman daal skte hain ye check krne ki zarurat nai hai ki
    //   agar phli node hai toh wo node ki traf point kre nai toh uske next mein saman jaye
    Node *temp_1 = new Node(INT_MIN); // odd
    Node *temp_2 = new Node(INT_MIN); // even
    Node *temp1 = temp_1;
    Node *temp2 = temp_2;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
        {
            temp2->next = temp;
            temp2 = temp2->next;
        }
        else
        {
            temp1->next = temp;
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
    temp2->next = NULL;         // list termination ke lie bhai
    temp1->next = temp_2->next; // dummy bhi skip krni hai na
    return temp_1->next;
}