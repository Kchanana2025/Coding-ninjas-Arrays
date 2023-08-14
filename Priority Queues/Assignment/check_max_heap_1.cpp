bool isMaxHeap(int arr[], int n)
{
    if (n == 0)
        return true;
    int parent = 0;
    int leftchildindex = 2 * parent + 1;
    int rightchildindex = 2 * parent + 1;
    if (leftchildindex < n)
    {
        if ((rightchildindex < n && arr[0] < arr[rightchildindex]) || arr[0] < leftchildindex)
        {
            return false;
        }
    }
    return isMaxHeap(arr + 1, n - 1);
}