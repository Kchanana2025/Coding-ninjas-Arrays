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
    node *newnode = new node(data);
    if (i == 0)
    {
    }
}
int main()
{
    int i;
    int data, i;
    node *head = takeinput();
    cin >> i;
    cin >> data;
    head = insertIthnode(head, i, data); // head sirf isliye return hua hai kyunki agar apne i=0 pe insertion krdi toh head update ho jayega
    print(head);
    return 0;
}
