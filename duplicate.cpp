#include <iostream>
using namespace std;

int duplicateNumber(int *arr, int size)
{
    int counter = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                counter++;
            }
        }
        if (counter == 2)
        {
            return arr[i];
        }
        else
            counter = 0;
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