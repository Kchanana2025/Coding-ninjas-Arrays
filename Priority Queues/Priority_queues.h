#include <vector>
class Priority_Queue
{
    vector<int> pq;

public:
    Priority_Queue
    {
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
    insert()
    {
    }
};