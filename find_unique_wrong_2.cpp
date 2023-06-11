
// WRONG CODE
#include <iostream>
using namespace std;

int findUnique(int *arr, int size)
{

    int counter = 0;

    for (int i = 0; i < size; i++)
    { // JAB ELEMENTS KA NO CHK KRKE KUCH O/P KRNA HOTA HAI
      // EK ELEMENT KO SABHI ELEMENTS SE CHK KRTE HAI
        for (int j = 0; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                counter++;
            }

            if (counter == 1)
            {
                return arr[i];
                counter = 0;
            }
            else
            {
                counter = 0;
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

        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}