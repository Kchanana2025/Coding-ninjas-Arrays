#include <iostream>
using namespace std;
void arrange(int *arr, int n)
{
    int num = 1;
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        arr[i] = num;
        num++;
        i++;
        arr[j] = num;
        num++;
        j--;
    }
    if (i == j)
    {
        arr[i] = num; // OR arr[j]=num;
    }
}
int main()
{
    int arr[10000];
    int n;
    int sum = 0;
    cout << "ENTER SIZE OF ARRAY";
    cin >> n;

    arrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }

    return 0;
}