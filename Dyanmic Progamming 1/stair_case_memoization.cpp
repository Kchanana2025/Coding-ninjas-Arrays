// O(n)
//  O(2n)=O(n)
//  this method is wrong ans[0] pr final ans hoga
//  toh ye swal iss tarike se  karo hi mt
#include <bits/stdc++.h>
using namespace std;
void stair_case(int x, int n, int *ans)
{
    int sum = 0;
    if (x == n)
    {
        return 1; // if x reaches to nth step return 1;i.e 1 way exists
    }
    if (x > n) // if x reaches greater than n then return 0;//no way exists
    {
        return 0;
    }
    if (ans[x] != -1) // that means ans[n] phle calculate ho chuka hai
    {
        return ans[x];
    }
    // agar cantrol yaha aaya mtlb ans[n] phle calculate nai hua hoga
    // that means calculate it and store it
    sum += stair_case(x + 1, n);
    sum += stair_case(x + 2, n);
    sum += stair_case(x + 3, n);
    ans[x] = sum;
}
int main()
{
    int t;
    cin >> t;
    while (t)
    {
        int n;
        cin >> n;
        int *ans = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            ans[i] = -1;
        }
        int x = 0;
        stair_case(x, n, ans);
        cout << ans[n];
        t--;
    }
    return 0;
}