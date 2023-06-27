#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
node *takeinput()
{

    int data;
    cout << "ENTER DATA";
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);

        if (head == NULL)

        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }

        cin >> data;
    }
    return head;
}
void print(node *head)
{

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}
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
