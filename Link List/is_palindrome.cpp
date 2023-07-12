// O(n*n/2)=O(n^2)
// O(n/2)
bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    Node *previous = NULL;
    Node *current = head;
    while (current->next != NULL) // current last node par na aa jaye
    {
        previous = current;
        current = current->next;
    }
    if (head->data == current->data)
    {
        previous->next = NULL;
        delete current;
        bool x = isPalindrome(head->next);
        return x;
    }
    else
    {
        return false;
    }
}