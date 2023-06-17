#include <iostream>
using namespace std;
int binarySearch(int *input, int size, int val)
{
    int start = 0;
    int end = size - 1;
    int mid;
    int flag = 0;
    while (start <= end)

    {
        mid = (start + end) / 2;
        if (input[mid] == val)
        {
            flag = 1;
            break;
        }
        else if (input[mid] < val)
        {
            start = mid + 1;
            flag = 0;
        }
        else
        {
            end = mid - 1;
            flag = 0;
        }
    }

    if (flag == 1)
    {
        return mid;
    }

    return -1;
}

int main()
{
    int x;
    int arr[30];
    int n;
    cout << "ENTER THE SIZE OF THE ARRAY";
    cin >> n;
    cout << "ENTER THE ELEMENTS OF ARRAY";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    int m = binarySearch(arr, n, x);
    cout << m;

    return 0;
}
