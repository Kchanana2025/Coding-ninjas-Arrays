Node *midPoint(Node *head)
{
    // Write your code here
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;                   // agar 1 2 3 4 mein middle ko 2 pe lana ho toh fast ko ek aage se shuru krte hain nai toh head hi
    while (fast != NULL && fast->next != NULL) // and lgega yaad rakhna ye baat
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}