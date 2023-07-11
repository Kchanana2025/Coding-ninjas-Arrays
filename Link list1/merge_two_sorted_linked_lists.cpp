// O(n+m)
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if (head1 == NULL && head2 == NULL)
    {
        return NULL;
    }

    else if (head1 == NULL)
        return head2;

    else if (head2 == NULL)
    {
        return head1;
    }
    Node *head = NULL;
    Node *temp = NULL;
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 && temp2) // DONO MEIN SE KOI BHI NULL NA HO JAYE
    {
        if (temp1->data <= temp2->data)
        {
            if (head == NULL)
            {
                head = temp1;
                temp = head;
            }
            else
            {
                temp->next = temp1;
                temp = temp->next; // isko else ke neeche kr rakha tha khud socho agar temp ka next btane se phle usko next kr dooge toh woh toh original link list mein aage badh jayega that is wrong
            }
            temp1 = temp1->next;
        }
        else if (temp1->data > temp2->data)
        {
            if (head == NULL)
            {
                head = temp2;
                temp = head;
            }
            else
            {
                temp->next = temp2;
                temp = temp->next;
            }
            temp2 = temp2->next;
        }
        // else//dono ka data equal hone ka case//ye repetitive code hai islye TLE ayega
        // {
        // 	     if(head==NULL)

        // 	       {
        // 		     head=temp1;
        // 		     temp=head;
        // 		     temp->next=temp2;
        // 		     temp=temp->next;
        // 	        }

        // 	     else
        // 		 {

        // 		temp->next=temp1;
        // 		temp=temp->next;
        // 		temp->next=temp2;
        // 		temp=temp->next;
        //      	}
        // 	temp1=temp1->next;
        // 	temp2=temp2->next;

        // }
    }
    while (temp1) // dono mein se jo bhi link list khtm nai hui wo main link list ke aage jud jaye
    {
        temp->next = temp1;
        temp = temp->next;
        temp1 = temp1->next;
    }
    while (temp2)
    {
        temp->next = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp->next = NULL;
    return head;
}
