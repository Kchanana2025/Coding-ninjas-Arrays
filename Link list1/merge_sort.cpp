// time:O(nlogn+n+n/2)=O(nlogn)
// space:O(logn)//coding ninjas pe galat dia hua h
#include <limits.h>
Node *midPoint(Node *head)
{
    // Write your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL && fast->next != NULL) // and lgega yaad rakhna ye baat
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *head1, Node *head2)
{

    if (head1 == NULL)
        return head2;

    else if (head2 == NULL)
    {
        return head1;
    }
    Node *head = new Node(INT_MIN); // dummy node
    Node *temp = head;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 && temp2) // DONO MEIN SE KOI BHI NULL NA HO JAYE
    {
        if (temp1->data <= temp2->data)
        {

            temp->next = temp1;
            temp = temp->next; // isko else ke neeche kr rakha tha khud socho agar temp ka next btane se phle usko next kr dooge toh woh toh original link list mein aage badh jayega that is wrong
            temp1 = temp1->next;
        }
        else if (temp1->data > temp2->data)
        {

            temp->next = temp2;
            temp = temp->next;

            temp2 = temp2->next;
        }
    }
    while (temp1) // dono mein se jo bhi link list khtm nai hui wo main link list ke aage jud jaye
    {
        temp->next = temp1;
        temp = temp->next;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        temp->next = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp->next = NULL;
    return head->next;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
    { // base case
        return head;
    }
    Node *mid = midPoint(head);
    Node *second_head = mid->next;
    mid->next = NULL;
    head = mergeSort(head); // adhi list merge hogi tab head update bhi toh hoga
    second_head = mergeSort(second_head);
    head = merge(head, second_head);
    return head;
}
