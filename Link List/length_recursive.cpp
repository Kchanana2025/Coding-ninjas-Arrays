// swal krte waqt hr ek edge case ke baare mein socha kro :-
// link list mein ek node hai /0 nodes hain sab kuch
int length(Node *head)
{
    if (head == NULL)
        return 0;
    // if(head->next==NULL)//no need upar wale case se hi ho jayega
    //         return 1;
    int x = length(head->next);
    return x + 1;
}