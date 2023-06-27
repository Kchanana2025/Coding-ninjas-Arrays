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
        next = NULL;
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
int LENGTH(node *head)
{
    node *temp = head;
    int counter = 0;
    // if(head==NULL)   //zrurat nai hai in dono lines ki if mein aur neeche wala code else mein::NO NEED BAEB
    // return 0;
    while (temp != NULL) // YE LOOP NO OF NODES TIMES HI CHALEGA ->COUNTER KI VALUE SAHI AYEGI
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

int main()
{
    node *head = takeinput();
    int counter = LENGTH(head);
    cout << "LENGTH OF LINK LIST  IS" << counter;
    return 0;
}