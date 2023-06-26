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
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    { // if hm temp->next! null kr dete toh last node ka data wo print nai krta
        cout << temp->data;
        temp = temp->next;
    }
}
int main()
{
    node n1(1);
    node n2(2);
    node n3(3);
    node n4(4);
    node n5(5);
    node *head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    print(head);

    return 0;
}