#include <iostream>
using namespace std;
int duplicateNumber(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++) // neeche wala loop tacle kr lega size-1 wale index wale element ko
    {
        for (int j = i + 1; j < size - 1; i++)
        { // isko peeche wale element check krne ki zrurat nai h kyunki unko phle hi dekh lia gya h
            if (arr[i] == arr[j])
            {
                return arr[i];
            }
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

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cout << duplicateNumber(input, size) << endl;
    }

    return 0;
}