#include <iostream>
using namespace std;
void arrange(int *arr, int n)
{
    int i = 0;
    int j = n - 1;
    int k = 1;
    while (i <= j)
    {
        if (i == j) // check n =7,mtlb kisi bhi odd value of n ke lie dekho
        {
            arr[i] = k;
            i += 1;
            k += 1;
        }
        else
        {
            arr[i] = k;
            k = k + 1;
            arr[j] = k;
            k += 1;
            j += 1;
            i = i + 1;
        }
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
