#include <vector>
#include <limits.h>
class PriorityQueue
{
    // Declare the data members here
    vector<int> pq;

public:
    PriorityQueue()
    {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element)
    {
        // Implement the insert() function here
        pq.push_back(element); // pq ke lie ye function call hui hai toh pq call krne se apne aap push_back call nai ho jayega kyunki ye vector ke functions hai
        int children = getSize() - 1;
        int parent = (children - 1) / 2;
        while (children > 0)
        {
            if (pq[parent] < pq[children])
            {
                swap(pq[parent], pq[children]);
                children = parent;
                parent = (children - 1) / 2;
            }
            else
                break;
        }
    }

    int getMax()
    {
        // Implement the getMax() function here
        if (isEmpty()) // pq ke lie ye function call hui hai toh pq call krne se apne aap isEmpty() call ho jaega pq.isEmpty likhoge toh error aa jayega
            return INT_MAX;

        return pq[0];
    }

    int removeMax()
    {
        // Implement the removeMax() function here
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentindex = 0;
        int leftchildindex = 2 * parentindex + 1;
        int rightchildindex = 2 * parentindex + 2;
        int maxindex = parentindex;
        while (leftchildindex < pq.size())
        {
            if (pq[leftchildindex] > pq[maxindex])
                maxindex = leftchildindex;
            if (rightchildindex < pq.size() && pq[rightchildindex] > pq[maxindex])
                maxindex = rightchildindex;
            if (maxindex == parentindex)
                break;
            swap(pq[maxindex], pq[parentindex]);
            parentindex = maxindex;
            leftchildindex = 2 * parentindex + 1;
            rightchildindex = 2 * parentindex + 2;
        }
        return ans;
    }

    int getSize()
    {
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here
        return pq.size() == 0;
    }
};