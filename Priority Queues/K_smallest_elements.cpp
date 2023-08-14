#include <queue>
vector<int> kSmallest(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        int largest = pq.top();
        if (largest > arr[i])
        {
            pq.pop(); // largest element is deleted
            pq.push(arr[i]);
        }
    }
    vector<int> v;
    for (int i = 0; i < k; i++) // or while (!pq.empty())
    {

        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}