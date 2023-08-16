// O(n)
// O(1)

bool isMaxHeap(int arr[], int n)
{
    // Write your code here
    int childIndex = 1;
    for (int i = 1; i < n; i++)
    {
        childIndex = i;
        int parentIndex = (childIndex - 1) / 2;
        if (arr[childIndex] > arr[parentIndex])
        {
            return false;
        }
    }
    return true;
}