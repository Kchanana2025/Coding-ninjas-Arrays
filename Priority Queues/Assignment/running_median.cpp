// I saw solution from neetcode
// O(nlogn)
//  O(n)
#include <queue>
#include <cmath>
void print_median(priority_queue<int> small_heap, priority_queue<int, vector<int>, greater<int>> large_heap)
{
    if (small_heap.size() == large_heap.size())
    {
        int average = 0;
        if (small_heap.size() != 0)
        {
            average = small_heap.top();
            average += large_heap.top();
        }
        average = average / 2;
        cout << average << " ";
    }
    else if (small_heap.size() > large_heap.size())
    {
        cout << small_heap.top() << " ";
    }
    else if (small_heap.size() < large_heap.size())
        cout << large_heap.top() << " ";
}
void findMedian(int *arr, int n)
{
    priority_queue<int> small_heap;                            // Maxheap
    priority_queue<int, vector<int>, greater<int>> large_heap; // Minheap
    int i = 0;
    while (i < n)
    {
        small_heap.push(arr[i]);

        if (i != 0 && ((small_heap.size() - large_heap.size()) > 1))
        {
            large_heap.push(small_heap.top());
            small_heap.pop();
        }

        else if (large_heap.size() != 0 && small_heap.top() > large_heap.top())
        {
            large_heap.push(small_heap.top());
            small_heap.pop();
        }
        // int lgana padhega phle
        if (large_heap.size() != 0 && ((int)large_heap.size() - (int)small_heap.size()) > 1)
        {
            small_heap.push(large_heap.top());
            large_heap.pop();
        }
        print_median(small_heap, large_heap);
        i++;
    }
}