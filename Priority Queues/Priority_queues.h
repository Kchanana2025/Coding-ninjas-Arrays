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
    void insert(int element)
    {
        pq.push_back(element);
        child_index = pq.size() - 1;
        parent_index = (child_index - 1) / 2;
        while (childindex > 0) // upar jaate jaate child root pr na pahuch jaye
        {
            if (pq[parent_index] > pq[childindex])
            {
                swap(pq[parent_index], pq[childindex]);
            }
            else
            {
                // agar if mein ghusa hi nai toh mtlb ab toh parent<child toh break krdo
                break;
            }
            child_index = parent_index;
            parent_index = (child_index - 1) / 2;
        }
    }

    int removeMin()
    {
        if (isEmpty())
            return 0;
        int parentindex = 0;
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int minindex;
        while (parentindex < pq.size())
        {
            int child_index_left = 2 * parentindex + 1;
            int child_index_right = 2 * parentindex + 2;
            if (child_index_left < pq.size() && child_index_right < pq.size())
            {
                minindex = pq[child_index_left] > pq[child_index_right] ? child_index_right : child_index_left;
            }
            else if (child_index_left < pq.size()) // when only left exists
            {
                minindex = child_index_left;
            }

            else
            {
                break;
            }
            if (pq[minindex] < pq[parentindex])
            {
                swap(pq[minindex], pq[parentindex]);
                parentindex = minindex; // ye neeche isliye likha because agar swap nai bhi hua tab bhi parentindex neeche toh jaaye tabhi toh loop terminate hoga nai bilkul nai agar swap nai hua toh break hi ho jayega isliye upar bhi likh skte hain aur likha hai
            }
            else
            {
                break;
            }
            //    parentindex = minindex;
        }
        return ans;
    }
};