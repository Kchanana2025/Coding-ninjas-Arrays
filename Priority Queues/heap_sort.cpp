//  O(nlogn)
//  O(1)
#include <algorithm>
void heapSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) // building of heap
    {
        int child = i;
        while (child > 0)
        {
            int parent = (child - 1) / 2;
            if (arr[parent] > arr[child])
            {
                std::swap(arr[parent], arr[child]);
            }
            else
            {
                break;
            }
            child = parent;
        }
    }
    // down heapifying n-1 times
    int size1 = n;
    while (size1 != 1)
    {

        int parent = 0;
        int leftchildindex = 2 * parent + 1;
        int rightchildindex = 2 * parent + 2;
        int minindex = parent;
        std::swap(arr[0], arr[size1 - 1]); // smallest element is reached at the end
        size1--;

        while (leftchildindex < size1)
        {

            if (arr[minindex] > arr[leftchildindex])
                minindex = leftchildindex;

            if (arr[rightchildindex] < arr[minindex] && rightchildindex < size1)
                minindex = rightchildindex;
            if (minindex == parent)
                break;
            std::swap(arr[minindex], arr[parent]);
            parent = minindex;
            leftchildindex = 2 * parent + 1;
            rightchildindex = 2 * parent + 2;
        }
    }
}