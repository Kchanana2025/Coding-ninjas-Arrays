Node *InsertNode(Node *head, int i, Node *newnode)
{
    if (head == NULL && i != 0) // agr i length se bda daal dooge toh idhar ruk jaega
    // dhyan se socho iss condition ke baare mein apne head ka next bhja aur index
    //   km kr dia agr max to max last node bhi insert krni hui apko toh bhi finally i=0 aa jaega last
    //   recursion call tak isliye ye contion lgai
    // ye condition (i>length-1) ko terminate kr degi
    // aur user i<0 bhi daal skta hai toh wo bhi tackle ho gya(mtlb waise daalega nai)
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