#include <iostream>
using namespace std;

void swapAlternate(int *arr, int size)
{
    // Write your code here
    int start = 0;
    int end = 1;
    while (end < size) // JAB BHI GARBAGE VALUE KI DIKKAT AAYE YE KROW
    {
        int temp;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start += 2;
        end += 2;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int *arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        swapAlternate(arr, size);
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        delete[] arr;
    }
}