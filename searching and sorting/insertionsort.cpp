#include <iostream>
using namespace std;

void insertionSort(int *input, int n)
{
    int j, temp;
    for (int i = 1; i < n; i++)
    { // i is started from 1 because we assume that 0th element is sorted i.e place at right position and we have to pick elements from position 1 and insert them at right position in sorted array
        temp = input[i];
        j = i - 1;
        while (j >= 0)
        {
            if (input[j] > temp)
            {
                input[j + 1] = input[j];
                j--;
            }
            else
                break;
        }
        input[j + 1] = temp;
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
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
