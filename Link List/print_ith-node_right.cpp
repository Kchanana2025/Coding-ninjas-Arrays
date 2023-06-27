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
void printIthnode(node *head, int i)
{
    node *temp = head;
    int j = 0;
    // temp!=NULL 2 things check kr raha hai
    // 1) no node is presnt
    // 2) i ko hum no of elements se zyada na daal dein
    // mtlb ki i agr 8 hai aur no of elements 4 hain  toh phir j<i toh around 8(j=0 to j=7) iterations ke lie rahega jbki nodes hi 4 hain toh hm temp!=NULL wali condition lga dete hain.(taki jitni nodes hain uss se aage na nikal jaye)
    while (temp != NULL && j < i)
    {
        temp = temp->next;
    }
    if (temp != NULL) // agr temp aage nikal gya hoga (total no of nodes se)toh phir hm kya hi print krege isliye ye check lga dia
    {
        cout << temp->data;
    }
}
int main()
{
    int i;
    node *head = takeinput();
    cout << "ENTER THE VALUE OF i";
    cin >> i;
    printIthnode(head, i);
    return 0;
}
