// O(nlogn)
//  O(2n)=O(n)
#include <queue>
int buyTicket(int *arr, int n, int k)
{
    queue<int> q;           // to store indices
    priority_queue<int> pq; // to store values

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        q.push(i);
    }
    int time = 0;
    while (!q.empty())
    {
        if (arr[q.front()] < pq.top())
        { // send to end of queue
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        else if (arr[q.front()] == pq.top()) // give ticket
        {
            pq.pop();
            time++;
            if (q.front() == k)
                return time;
            q.pop();
        }
    }
}
