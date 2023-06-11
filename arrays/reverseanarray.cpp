#include <iostream>
using namespace std;
void printarray(int A[], int n)
{
    for (int k = 0; k < n; k++)
        cout << A[k] << " ";
}
void reverse(int A[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    int n, A[30], i;
    // Take array inout from user
    cout << "Enter size of array" << endl;
    cin >> n;
    cout << "Enter the elements of array: "; // Array Input
    for (i = 0; i <= n - 1; i++)
    {
        cin >> A[i];
    }
    reverse(A, i);
    printarray(A, i);

    // cout << "Elements of Array are" << endl; // Printing Elements Of An Array
    // for (i = 0; i <= n - 1; i++)
    //     cout << A[i] << endl;
    // printarray(A, n);

    // cout << A << endl;
    //  cout << &A[0];
}