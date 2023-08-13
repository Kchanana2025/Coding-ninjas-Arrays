// method 1 is one function in priority_queues.h
int remove_min()
{
    if (isEmpty())
        return 0;
    int parentindex = 0;
    int leftchildindex = 2 * parentindex + 1;
    int rightchildindex = 2 * parentindex + 2;
    while (leftchildindex < pq.size())
    {
        int minindex = parentindex;
        if (pq[leftchildindex] < pq[minindex])
        {
            minindex = leftchildindex;
        }
        if (rightchildindex < pq.size() && pq[rightchildindex] < pq[minindex]) // else if nai lgega idhar we want minimmum index to minum out of all 3 toh comparison toh krne do
        {
            minindex = rightchildindex;
        }
        if (parentindex == minindex)
            break;
        else
        {
            swap(pq[minindex], pq[parentindex]);
            minindex = parentindex;
        }
        leftchildindex = 2 * parentindex + 1;
        rightchildindex = 2 * parentindex + 2;
    }
}