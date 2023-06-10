#include <iostream>
#include <climits>
using namespace std;
// first element to max isliye nai choose kia initially taki jab n=0 ayega toh dikkat ayega
//  aur max ko 0 ke equal isliye nai likha kyunki negative elements tackle na ho pate
int main()
{
    int n, A[30], i;
    // Take array inout from user
    cout << "Enter size of array" << endl;
    cin >> n;
    cout << "Enter the elements of array"; // Array Input
    for (i = 0; i <= n - 1; i++)
        cin >> A[i];

    cout << "Elements of Array are" << endl; // Printing Elements Of An Array
    for (i = 0; i <= n - 1; i++)
        cout << A[i] << endl;

    int max = INT_MIN;
    for (i = 0; i < n; i++)
    {

        if (A[i] > max)
        {
            max = A[i];
        }
    }
    cout << "MAX:" << max;
}