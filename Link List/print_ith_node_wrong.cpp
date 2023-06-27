// right code padhlo smjh aa jayega kya galat h
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
void printIthNode(node *head, int i)
{
    node *temp = head;
    int j = 0;
    while (j < i)
    {
        temp = temp->next;
        j++;
    }
    cout << temp->data;
}

int main()
{
    int i;
    node *head = takeinput();
    cout << "ENTER THE VALUE OF i";
    cin >> i;
    printIthNode(head, i);
    return 0;
}
