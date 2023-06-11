int findUnique(int *arr, int size)
{
    int temp;
    int counter = 0;
    for (int i = 0; i < size; i++)
    { // JAB ELEMENTS KA NO CHK KRKE KUCH O/P KRNA HOTA HAI EK ELEMENT KO SABHI ELEMENTS SE CHK KRTE HAI
        temp = arr[i];
        for (int j = 0; j < size; j++)
        {

            if (temp == arr[j]) // OR arr[i]==arr[j]
            {
                counter++;
            }
        }
        if (counter == 1)
        {
            return arr[i];
            counter = 0;
        }
        counter = 0;
    }
}
#include <iostream>
using namespace std;

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