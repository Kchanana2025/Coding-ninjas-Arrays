#include <iostream>
#include <algorithm>
using namespace std;
void intersection(int *input1, int *input2, int size1, int size2)
{
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (input1[i] == input2[j])
            {
                cout << input1[i] << " ";

                input2[j] = 7890890; // taki input1 ka koi aur element iss particular input[j] ke match na ho jaye isliye idhar koi aur value fit krdi
                input1[i] = 789089;  // OR break; taki input1 ka wohi element dobara kisi aur input2 ke kisi element se match hoke print na ho jaye
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

        int size1, size2;

        cin >> size1;
        int *input1 = new int[size1];

        for (int i = 0; i < size1; i++)
        {
            cin >> input1[i];
        }

        cin >> size2;
        int *input2 = new int[size2];

        for (int i = 0; i < size2; i++)
        {
            cin >> input2[i];
        }

        intersection(input1, input2, size1, size2);

        delete[] input1;
        delete[] input2;

        cout << endl;
    }

    return 0;
}