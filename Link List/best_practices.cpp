// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    { // CONSTRUCTOR FOR NODE INITIALIZATION
        this->data = data;
        this->next = NULL;
    }
};
int main()
{
    // Write C++ code here
    Node n1(5);
    Node *head = &n1;
    Node n2(10);
    n1.next = &n2;
    // TWO WAYS TO PRINT DATA
    // M1cout<<n1.data<<" "<<n2.data<<" ";
    // M2
    cout << head->data << " ";
    head = head->next;
    cout << head->data << " ";
    Node *n3 = new Node(80);
    n2.next = n3;
    Node *n4 = new Node(30);
    n3->next = n4;
    head = head->next;
    cout << head->data << " ";
    head = head->next;
    cout << head->data << " ";

    return 0;
}