Node *InsertNode(Node *head, int i, Node *newnode) // agar length of 5 ki link list mein 5th index se zyada ni daal skte nai toh insert nai hoga normal insertion mein toh 4th index tak allowed tha isme better code likh dia
{
    if (head == NULL && i != 0) // agr i length se bda daal dooge toh idhar ruk jaega
    // dhyan se socho iss condition ke baare mein apne head ka next bhja aur index km kr dia agr max to max last node bhi insert krni hui apko toh bhi finally i=0 aa jaega last recursion call tak isliye ye contion lgai i>length-1 ko terminate krne waali wali
    {
        return head;
    }
    if (i == 0) // isme head==NULL aur  case of normal link list(jisme 0th node se phle node lgana hai) bhi tackle ho jayega
    {
        newnode->next = head;
        head = newnode;
        return head;
    }

    Node *temp = InsertNode(head->next, i - 1, newnode);
    head->next = temp;
    return head;
}