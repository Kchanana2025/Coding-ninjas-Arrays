// O(n)
// O(n)
int findNodeRec(Node *head, int n)
{

    if (head == NULL)
        return -1;

    if (head->data == n)
    {
        return 0;
    }

    int x = findNodeRec(head->next, n);
    if (x == -1) // ye cheez lgana bhul gai thi mai
        return -1;
    else
    {
        return x + 1;
    }
}