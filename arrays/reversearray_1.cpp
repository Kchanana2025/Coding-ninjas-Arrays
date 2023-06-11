#include <iostream>
using namespace std;
void reverse(int arr[], int n)
{
    int temp;
    int i, j;
    for (i = 0, j = n - 1; i < j; i++, j--)
    { // i=j wala ek extra operation bhi kyun krien jab i <j mein kaam chl rha h

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
int main()
{
    int arr[30];
    int n, temp;
    cout << "enter n";
    cin >> n;
    cout << "enter elements";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverse(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}
