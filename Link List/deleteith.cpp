// time:O(n) agar last node delete krne ko kaha hai toh second last node tak iterate kro toh operations will be n-1 which is O(n) hi
// space:O(1)
node *deleteIthNode(node *head, int i)
{ // i is basicallly index bro
    int count = 0;
    node *temp = head;
    if (i == 0)
    {

        head = head->next;
        delete temp;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next != NULL) // this means that temp has reached the required node OR we can say that user has not entered i>length of link list-1
    {
        node *a = temp->next;
        node *b = a->next;
        temp->next = b;
        delete a; // we wanted to delete a (beech wala node) that is the reason we didnt write temp->next=temp->next->next
    }
    return head;
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    int i;
    node *head = takeinput();
    cout << "ENTER THE VALUE OF i";
    cin >> i;
    head = deleteIthNode(head, i);
    print(head);
    return 0;
}
