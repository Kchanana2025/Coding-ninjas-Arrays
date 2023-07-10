// int length(Node *head)
// {
//     if (head == NULL)
//         return 0;
//     Node *temp = head;
//     int counter = 0;
//     while (temp != NULL)
//     {
//         temp = temp->next;
//         counter++;
//     }
//     return counter; // i.e length of the link list
// }
// iterative appoach of calculating length isliye likh rakha hai kyunki maine mistake krri thi iss code mein counter ki jagah counter+1 return kia tha
// temp!=NULL mein counter return hota hai aur temp->next!=NULL ke case mein counter +1 return hota hai

int length(Node *head) // jo question recursion se ho skta hai usko recursion se kro
{
    if (head == NULL)
        return 0;
    return 1 + length(head->next);
}

Node *appendLastNToFirst(Node *head, int n)
{

    int len = length(head);
    int i = len - n; // index of the node from which we wish to start the link list
    // uss phli node ka index jisko uthake hamien shuru mein lana h
    if (head == NULL || i > len - 1 || head->next == NULL) // hm ye sari cheezien isliye likh rhe hain kyunki agar nai likhenge toh NULL->ajaega aur segmentataion fault ho jayega
    // i > len - 1 ka mtlb hai ki max to max hm last node se link list start kr skte hain agar i usse bda aaya toh koi appending nai ho skti aur agar i = 0 ho gya mtlb apne sari nodes ko append krne ko keh dia toh wo bhi sahi nai haii
    {
        return head;
    }
    Node *temp = head;
    int counter = 0;
    while (temp != NULL && counter < i - 1)
    {
        temp = temp->next;
        counter++;
    }
    Node *new_head = temp->next;
    temp->next = NULL;
    Node *temp1 = new_head;
    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp1->next = head;
    head = new_head;
    return head;
}
