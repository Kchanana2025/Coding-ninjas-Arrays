#include <iostream>
using namespace std;
int fibo(int n)
{
    // base case
    if (n <= 1) // ye n ki values 0/1 ki ho payengi beacuse negative nos ka fibbonacci nikal nai skte and secondly as a base case bhi as 0 or 1 hi call hoga
    {
        return n;
    }

    int a = fibo(n - 1);
    int b = fibo(n - 2);
    return a + b;
}
int main()
{
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}