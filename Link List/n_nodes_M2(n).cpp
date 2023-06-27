#include <iostream> //LINK_LIST INPUT KRKE PRINT KRNA CHAHTE RHE HAI HUM
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
// har function jo object ke bina call hota hai except for static functions wo class ke bahar define hota hai
node *takeinput() // is function ka kaam hai to create link list and to return head of that link list
{                 // arrays hm size puchte thee user se isme hum nai puchege because wohi toh avoid krna tha hamien isliye humne list list introduce kri
                  // hm ya toh data enter krwake aise rakh skte hain ki jaise hi data -1 ho bss kro aur mat badhana LL ::Limitation ye hogi ki -1 ni daal skte
                  // ya phir hum phli node enter krwake yes no puch skte hain user se ki aur krwana chahoge?

    int data;
    cout << "ENTER DATA";
    cin >> data;
    node *head = NULL; // initially null rakhte hai taki neeche jaake filter lga ske ki bhai agr head null hai toh head mein first node ka address daal do
    node *tail = NULL; // tail bhi use krege taki while loop ki vjah se hmari code ki complexity se n sqare se ghatke n ho jaye(tail na use krne pe nayi node daalne ke lie baar baar last node tak traverse krna padhta tha)
    while (data != -1)
    {
        node *newnode = new node(data); // isko dyanmically allocate kia hai bcz while loop khtm hone ke baad apki node deallocate na ho jaye
                                        // newnode pointer stack memory mein hai wo deallocate ho jayega aur har naye node pe newnode hi point krega, jbki nayi node jo bani hai wo dyanmically bani hai toh wo heap memory mein hai

        //    node *newnode = new node(data); // ISS SE DATA TAB TK RAHEGA JAB TK AAP DELETE NA KRDO
        // node n(data);  IF WE STATICALLY ALLOCATE NODES HOGA KYA KI HR ITERATION KE BAAD HMARA NODE GAYAB HO GAYEGA KYUNKI USS VARIABLE KA SCOPE TOH SIRF USS FUNCTION ISS USSS ITERATION TAK HAI
        // head=&n;      WE SHOULDNT DO THIS BECAUSE AISE TOH HEAD UPDATE HOTA RAHEGA AND WE WANT KI HEAD SIRF FIRST ELEMENT KI VALUE RAKHE

        if (head == NULL)

        {
            head = newnode;
            tail = newnode;
        }
        else // agle node ka address pichle node mein daldo
        {
            tail->next = newnode;
            tail = tail->next; // OR tail=newnode;
        }

        cin >> data;
    }
    return head;
}
// BHAI DEKH JAB EK BHI NODE NAI HOGI TAB DONO NULL HONGE JAB EK EK NODE AYEGI TOH DONO HEAD TAIL USSI EK NODE KO
//  POINT KREGE JAB AYEGA EK SE ZYADA NODE TOH HEAD WILL POINT TOWARD FIRST NODE AND TAIL WILL POINT TOWARDS LAST NODE
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