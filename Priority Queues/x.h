#include <vector>
class Priority_Queue
{
    vector<int> pq;
    int nextindex;

public:
    Priority_Queue
    {
        nextindex = 0;
    }
    bool isEmoty
    {
        return pq.size() == 0;
    }
    int getsize()
    {
        return pq.size();
    }
    int getMin()
    {
        if (isEmpty())
            return INT_MAX;

        return pq[0];
    }
    insert(int data)
    {
        pq.push_back(data);
        nextindex++;
    }
};