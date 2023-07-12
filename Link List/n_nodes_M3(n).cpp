// time:O(n)
// space:O(n)
//  Link list input krwake print krwana chah rhe hain hum
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    { // contructor
        this->data = data;
        this->next = NULL;
    }
};
// Every function that is called without object must be defined outside class expect for static functions
node *takeinput() // this function creates a link list and returns its head
{
    int data;
    char choice;

    node *head = NULL; // head is a pointer of type node
    node *tail = NULL; // tail is a pointer of type node
    do
    {
        cout << "ENTER DATA";
        cin >> data;
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next; // or tail=newnode
        }
        cout << "Do you wish to continue type n of no";
        cin >> choice;

    } while (choice != 'n'); // while ki statement ke baad semicolon lgta hai
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
    node *head = takeinput();
    print(head);
    return 0;
}
