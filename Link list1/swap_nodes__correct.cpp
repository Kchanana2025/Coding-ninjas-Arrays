***************************************************************** /
// O(n)
// O(1)
#include <limits.h>
    Node *swapNodes(Node *head, int i, int j)
{

    if (head == NULL)
        return head;
    else if (i == j) // i forgot this test case
        return head;
    //    i>=len-1|| j>=len-1//aisa test case toh hi denge ig
    //    return head;
    Node *dummy = new Node(INT_MIN);
    dummy->next = head;
    head = dummy;
    Node *temp1 = head;
    Node *temp2 = head;
    int count = 0;
    Node *a;
    Node *b;
    Node *temp = head->next; // initially wo set kro temp aur previous ki values jo i=0 position milne pr  a,temp1 ko assign ho
    Node *previous = head;
    int pos = 0;
    while (temp != NULL)
    {
        if (i == pos)
        {
            temp1 = previous;
            a = temp;
        }
        else if (j == pos)
        {
            temp2 = previous;
            b = temp;
        }
        previous = temp;
        temp = temp->next;
        pos++;
    }
    Node *a_next = a->next;
    Node *b_next = b->next;

    if (abs(j - i) == 1)
    {

        temp1->next = b;
        b->next = a;
        a->next = b_next;
    }
    else
    {

        temp1->next = b;
        b->next = a_next;
        temp2->next = a;
        a->next = b_next;
    }

    return head->next;
}