#include <iostream>
using namespace std;
void bubbleSort(int input[], int n)
{ // APP2
    for (int j = n - 1; j >= 1; j--)
    {
        int counter = 0; // i ka kaam counter kr rha
        for (int i = 0; i < n - 1 - counter; i++)
        {
            if (input[i] > input[i + 1])
            {
                int temp = input[i];
                input[i] = input[i + 1];
                input[i + 1] = temp;
            }
        }
        counter++;
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
