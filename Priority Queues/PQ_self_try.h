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
    int child_index = nextindex - 1;
    int parent_index = (child_index - 1) / 2;
    while (child_index > 0 && pq[parent_index] > pq[child_index])
    {

        swap(pq[parent_index], pq[child_index]);
        child_index = parent_index;
        parent_index = (child_index - 1) / 2;
    }
    int remove_min()
    {
        parentindex = 0;

        while (parentindex < pq.size())
        {
            child_index_left = 2 * parent_index_left + 1;
            child_index_right = 2 * parent_index_right + 1;
            if (child_index_left < pq.size() && child_index_right < pq.size())
            {
                minindex = pq[child_index_left] > pq[child_index_right] ? child_index_right : childindex_left;
                if (pq[minindex] < pq[parentindex])
                {
                    swap(pq[minindex], pq[parentindex]);
                    parentindex = minindex;
                }
                else
                {
                    break;
                }
            }
            else if (child_index_left < pq.size()) // right mein check krne ki zarurat nai hai CBT hi hai wo
            {
                if (pq[child_index_left] < pq[PI])
                {
                    swap(pq[child_index_left], pq[PI]);
                    PI = child_index_left;
                }
            }
            else
            {
                break;
            }
        }
    }
    int remove_min_anothertry() // too much of repetitive code
    {
        int removeMin()
        {
            if (isEmpty())
                return 0;
            int parentindex = 0;
            int ans = pq[0];
            pq[0] = pq[pq.size() - 1];
            pq.pop_back();
            while (parentindex < pq.size())
            {
                int child_index_left = 2 * parentindex + 1;
                int child_index_right = 2 * parentindex + 1;
                if (child_index_left < pq.size() && child_index_right < pq.size())
                {
                    int minindex = pq[child_index_left] > pq[child_index_right] ? child_index_right : child_index_left;
                    if (pq[minindex] < pq[parentindex])
                    {
                        swap(pq[minindex], pq[parentindex]);
                        parentindex = minindex;
                    }
                    else
                    {
                        break;
                    }
                }
                else if (child_index_left < pq.size()) // right mein check krne ki zarurat nai hai CBT hi hai wo
                {
                    if (pq[child_index_left] < pq[parentindex])
                    {
                        swap(pq[child_index_left], pq[parentindex]);
                        parentindex = child_index_left;
                    }

                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }

            return ans;
        }
    }
};