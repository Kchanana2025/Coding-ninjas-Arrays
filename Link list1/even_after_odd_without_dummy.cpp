// O(n)
// O(1)
// this is very bada code never forget to make dummy if it can make your soln small and easy to unserstand
Node *evenAfterOdd(Node *head)
{
  // write your code here
  if (head == NULL)
    return head;
  Node *head_even = NULL, *tail_even = NULL, *head_odd = NULL, *tail_odd = NULL;
  while (head != NULL)
  {
    if (head->data % 2 == 0)
    {
      if (head_even == NULL)
      {
        head_even = head;
        tail_even = head;
      }
      else
      {
        tail_even->next = head;
        tail_even = head;
      }
    }
    else
    {
      if (head_odd == NULL)
      {
        head_odd = head;
        tail_odd = head;
      }
      else
      {
        tail_odd->next = head;
        tail_odd = head;
      }
    }
    head = head->next;
  }
  if (tail_odd != NULL)
    tail_odd->next = head_even;
  if (tail_even != NULL)
    tail_even->next = NULL;
  if (head_odd == NULL)
    return head_even;
  else
    return head_odd;
}