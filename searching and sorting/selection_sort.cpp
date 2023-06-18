#include <iostream>
using namespace std;
int Selectionsort(int *arr, int n)
{

    for (int j = 0; j <= n - 2; j++)
    { // 0 to n-1 =total n-2 rounds(1 less round because after n-1 rounds array will
        // be sorted last element will reach the required place)
        int min = arr[j], minindex = j;
        for (int i = j + 1; i < n; i++)
        { // for finding minimum in jth round
            if (arr[i] < min)
            {
                min = arr[i];
                minindex = i;
            }
        }
        swap(arr[j], arr[minindex]);
    }
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
    Selectionsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
