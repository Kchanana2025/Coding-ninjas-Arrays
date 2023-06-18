#include <iostream>
using namespace std;

void bubbleSort(int input[], int n) // APP1
{
    for (int i = 0; i <= n - 2; i++)
    { // n-1 rounds(0 to n-2=total n-1 rounds)
        for (int j = 0; j <= n - 2 - i; j++)
        {
            if (input[j + 1] < input[j])
            {
                swap(input[j + 1], input[j]);
            }
        }
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
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
