#include <iostream>
using namespace std;
int findUnique(int *arr, int size)
{
    for (int i = 0; i <= size - 1; i++) // neeche wala loop tacle kr lega size-1 wale index wale element ko
    {
        int j;
        for (j = 0; j <= size - 1; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                break;
            }
        }
        if (j == size)
        {
            return arr[i];
        }
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
        int *input = new int[size];

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}
