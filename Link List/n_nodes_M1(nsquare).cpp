#include <iostream> //LINK_LIST INPUT KRKE PRINT KRNA CHAHTE RHE HAI HUM
using namespace std;
class node
{
public:
    int data;
    node *next;

public:
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// har function jo object ke bina call hota hai except for static functions wo class ke bahar define hota hai
node *takeinput() // is function ka kaam hai to create link list and to return head of that link list
{                 // arrays hm size puchte thee user se isme hum nai puchege because wohi toh avoid krna tha hamien isliye humne list list introduce kri
    // hm ya toh data enter krwake aise rakh skte hain ki jaise hi data -1 ho bss kro aur mat badhana LL ::Limitation ye hogi ki -1 ni daal skte
    // ya phir hum phli node enter krwake yes no puch skte hain user se ki aur krwana chahoge?

    int data;
    cout << "ENTER DATA";
    cin >> data;
    node *head = NULL; // initially null rakhte hai taki neeche jaake filter lga ske ki bhai agr head null hai toh head mein first node ka address daal do
    while (data != -1)
    {
        node *newnode = new node(data); // isko dyanmically allocate kia hai bcz while loop khtm hone ke baad apki node deallocate na ho jaye
        if (head == NULL)               // newnode pointer stack memory mein hai wo deallocate ho jayega aur har naye node pe newnode hi point krega jsbki nayi node jo bani hai wo dyanmically bani hai toh wo heap memory mein hai
        {
            head = newnode;
        }
        else // agle node ka address pichle node mein daldo
        {
            // head->next=newnode; //2nd node ke lie this statement is absolutely  right but uske lawa bakiyo ke lie nai
            //  hai hamien iterate krke jana parega second last node pe aur phir uske next mein agle node ka address dalna hoga
            node *temp = head;         // we never use head,taki head ghum na jaye uski jagah we make copy of head to iterate over lists
            while (temp->next != NULL) // second last node hi toh null hai
            {                          // temp bhi deacllocate ho jayegi hr ek iteration ke baad wo bhi stack memory mein hi initialize hua hai
                temp = temp->next;
            }
            // iss loop se bahar aane ke baad temp ke pass second last node ka address pda hoga
            temp->next = newnode;
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

int main()
{
    node *head = takeinput();
    print(head);
    return 0;
}