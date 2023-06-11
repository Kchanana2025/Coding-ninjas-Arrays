#include <iostream>
using namespace std;
int main()
{
    int N, A[1000000]; // NEVER WRITE A[n];
    int sum = 0;
    int i;
    cout << "Enter an integer N ie size of array";
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (i = 0; i < N; i++)
    {
        sum = sum + A[i];
    }
    cout << "Sum" << sum;
}
