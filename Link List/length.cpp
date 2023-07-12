// time:O(n)
// space:O(1)
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
