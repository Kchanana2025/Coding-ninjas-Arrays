// time:O(n) socho agar last index pe node insert krni hui toh second last node tak traverse karoge na.
// space: O(1)
//  LL=4 mein i=3 max daal skte iss code mein
node *insertIthnode(node *head, int i, int data)
{
    int count = 0;
    node *temp = head;
    node *newnode = new node(data);
    if (i == 0)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    while (temp != NULL && count < i) // we have done temp!=NULL because if user enter i>size of link list then segmentation fault na aa gaye (NULL->)jaisa situation
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL) // if while loop  is terminated because of temp reaching the desired location(count<i wali condition ke false hone ki vjah se and not temp=NULL only
    {
        node *a = temp->next;
        temp->next = newnode;
        newnode->next = a;
    }
    return head;
}
int main()
{
    int data, i;
    node *head = takeinput();
    cin >> i;
    cin >> data;
    head = insertIthnode(head, i, data); // head sirf isliye return hua hai kyunki agar apne i=0 pe insertion krdi toh head update ho jayega
    print(head);
    return 0;
}
