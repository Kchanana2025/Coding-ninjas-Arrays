// O(2^n)
// O(n)
// must watch needcode video
#include <bits/stdc++.h>
using namespace std;
int stair_case(int x, int n)
{
    const long long int factor = 1000000007; // this is important const long long int
    // dont write 10^9+7;
    int sum = 0;
    if (x == n)
    {
        return 1; // if x reaches to nth step return 1;i.e 1 way exists
    }
    if (x > n) // if x reaches greater than n then return 0;//no way exists
    {
        return 0;
    }
    sum += stair_case(x + 1, n) % factor;
    sum += stair_case(x + 2, n) % factor;
    sum = sum % factor; // hr sum ke baad %factor krna hota h,taki int ki range se bahar chla jaye
    sum += stair_case(x + 3, n) % factor;
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
        int x = 0;
        cout << stair_case(x, n) << endl;
        t--;
    }
    return 0;
}