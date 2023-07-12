// O(n)
// O(1)
int findNode(Node *head, int n)
{
    Node *temp = head;
    int counter = 0;
    while (temp != NULL)
    {
        if (temp->data == n)
        {
            break;
        }
        counter++;
        temp = temp->next;
    }
    if (temp == NULL || head == NULL)
        return -1;
    else
        return counter;
}