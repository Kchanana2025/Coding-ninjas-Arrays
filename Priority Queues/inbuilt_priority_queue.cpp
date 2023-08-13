#include <queue>
#include <iostream>
using namespace std;
int main()
{
    priority_queue<int> pq;
    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(35);
    pq.push(42);
    cout << pq.size();
    cout << pq.top();
    cout << endl;
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    return 0;
}