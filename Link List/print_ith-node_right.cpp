// Time:O(n)(agar last node hi print krne ko kehdi)
// space:O(1)
void printIthnode(node *head, int i)
{
    node *temp = head;
    int j = 0;
    // temp!=NULL 2 things check kr raha hai
    // 1) no node is presnt i.e head kahin NULL toh nai hai
    // 2) i ko hum no of elements se zyada na daal dein
    // mtlb ki i agr 8 hai aur no of elements 4 hain  toh phir j<i toh around 8(j=0 to j=7) iterations ke lie rahega jbki nodes hi 4 hain toh hm temp!=NULL wali condition lga dete hain.(taki jitni nodes hain uss se aage na nikal jaye)
    while (temp != NULL && j < i)
    {
        temp = temp->next;
        j++;
    }
    if (temp != NULL) // agr temp aage nikal gya hoga (total no of nodes se)toh phir hm kya hi print krege isliye ye check lga dia
    // aur secondly isliye bhi loop khtm ho skta ho kyunki temp hi NULL ho(link list hi khali ho)
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
