#include <queue>
vector<int> kLargest(int input[], int n, int k)
{

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++) // klogk
    {
        pq.push(input[i]);
    }
    for (int i = k; i < n; i++) //(n-k)logk
    {
        int smallest = pq.top();
        if (smallest < input[i]) // agar smallestest input[i] se chota hai toh wo larest elements ki list mein hona deserve nai krta usko bahar nikalo aur input[i] ko min heap mein push kro
        {
            pq.pop(); // smallest element is deleted
            pq.push(input[i]);
        }
    }
    vector<int> v;
    for (int i = 0; i < k; i++) // or while (!pq.empty())// klogk
    {

        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}