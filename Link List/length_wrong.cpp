// YE QUESTION KI EK WRONG UNDERSTANDING HAI JISKA CODE KR RAKHA HAI
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
// READ QUESTION GALAT INTERPRET KIA HUA HAI DATA=-1 TERMINATOR(TAKE INPUT MEIN) USE KRNE PAR YE NEED NAI HAI LIKHNE KI KI JAB DATA=-1 AAYE TERMINATE KRDO AUR METHOD2 OF TAKE INPUT YES/NO TERMINATOR USE KRNE PR TOH WAISE HI KOI NEED NAI HAI TERMINATOR KI
int Length(node *head) // FALTU CODE HAI YE KOI SENSE NI BNTI -1 element daal hi nai skte take input mein hi -1 nai daalega wo bss question mein ye baat dhyan rakhne ko bol rhe hai ki -1 ko as an element consider mt kr lena pr uske lie condtion lgane ki koi zrurat nai hai
{
    // Write your code here
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        if (temp->data != -1)
        {
            count++;
        }
        else if (temp->data == -1)
        {
            return count;
        }
        temp = temp->next;
    }
    return count;
}

int main()
{
    node *head = takeinput();
    int counter = Length(head);
    cout << "LENGTH OF LINK LIST  IS" << counter;
    return 0;
}
