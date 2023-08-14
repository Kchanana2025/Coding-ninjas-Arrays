// O(n*k)log(n*k)
// O(n*k)
#include <queue>
vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input[i]->size(); j++)
        {
            pq.push(input[i]->at(j));
        }
    }
    vector<int> v;
    while (!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}