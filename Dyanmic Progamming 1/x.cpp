#include <bits/stdc++.h>
using namespace std;
int staircase_helper(int x, int n, int *ans)
{
    const long long int factor = 1000000007; // this is important const long long int
    // dont write 10^9+7;write it 1000000007
    int sum = 0;
    if (x == n)
    {
        return 1; // if x reaches to nth step return 1;i.e 1 way exists
    }
    if (x > n) // if x reaches greater than n then return 0;//no way exists
    {
        return 0;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    sum += staircase_helper(x + 1, n, ans) % factor;
    sum += staircase_helper(x + 2, n, ans) % factor;
    sum = sum % factor; // hr sum ke baad %factor krna hota h,taki int ki range se bahar chla jaye
    sum += staircase_helper(x + 3, n, ans) % factor;
    sum = sum % factor;
    ans[n] = sum;
    return ans[n];
}
int stair_case(int x, int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    int solution = staircase_helper(x, n, ans);
    return solution;
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