// O(2^n)
// O(n)
#include <bits/stdc++.h>
using namespace std;
int stair_case(int n)
{
    const long long int factor = 1000000007;
    int sum = 0;
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    sum += stair_case(n - 1) % factor;
    sum = sum % factor;
    sum += stair_case(n - 2) % factor;
    sum = sum % factor; // hr sum ke baad %factor krna hota h,taki int ki range se bahar chla jaye
    sum += stair_case(n - 3) % factor;
    sum = sum % factor;
    return sum;
}
int main()
{
    int t;
    cin >> t;
    while (t)
    {
        int n;

        cin >> n;
        int sum = stair_case(n);
        cout << sum << endl;
        t--;
    }
    return 0;
}
