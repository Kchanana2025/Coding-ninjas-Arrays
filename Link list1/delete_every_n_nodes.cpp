// O(n)
// O(1)
#include <limits.h>
Node *skipMdeleteN(Node *head, int m, int n)
{
    Node *dummy = new Node(INT_MIN);
    dummy->next = head;
    head = dummy;
    Node *temp = head;
    if (head->next == NULL) // link list khali hai ya m=0 hai means sbko delete krna hai
    {
        return NULL;
    }
    if (m == 0 && n == 0)
    {
        return head->next;
    }
    else if (n == 0) // kuch bhi delete ni krna
    {
        return head->next;
    }
    else if (m == 0)
        return NULL;
    int m1 = m; // inko initialize kro bhai
    int n1 = n;
    while (temp->next != NULL) // galat likh rakha tha ie temp!=NULL bhai temp dummy hai jab usko next NULL ho jayega rukoge hi because na wo skip kr skta hai kyunki jahan temp hota hai wo usko skip kr chuka hota hai toh skip kisko krega aur delete jisko krna hota hai uske beeche temp beetha hota hai toh NULL ko toh delete karoge nai toh ja tamp->next null ho jaye bahar aa jao
    {
        m1 = m;
        n1 = n;
        while (m1)
        {
            if (temp->next != NULL) // dummy lgane ke baad conditions sahi se likha kro
            {
                temp = temp->next;
            }
            else
            {
                return head->next;
            }
            m1--;
        }
        //  cout<<temp->next->data;
        while (n1)
        {
            // cout<<temp->next->data;
            if (temp != NULL && temp->next != NULL) // second condition isliye hai kyunki jab next null hoga tab bhi delete nai krna hoga hamien aur agar ye condition nai lgai toh neeche wala code run krke dekho segmentation fault aajaega
            {
                Node *a = temp->next;
                temp->next = a->next;
                delete a;
            }
            else
            {
                return head->next;
            }
            n1--;
        }
    }
}
