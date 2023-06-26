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
void print(node *head) // JO FUNCTIONS BINA KISI OBJECT KE CALL HOTE HAIN UNKO CLASS KE BAHAR HI DEFINE KRTE HAIN EXCEPT STATIC FUNCTIONS

{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    node *n1 = new node(10); // this is simply a variable of type node ,(this is not a node)(n1)
    node *head = n1;         // this is simply a variable of type node ,(this is not a node)(head)
    node *n2 = new node(20);
    n1->next = n2;
    node *n3 = new node(30);
    n2->next = n3;
    node *n4 = new node(40);
    n3->next = n4;
    node *n5 = new node(50);
    n4->next = n5;
    print(head);
    return 0;
}