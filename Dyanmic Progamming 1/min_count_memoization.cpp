#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
int minCount_helper(int n, int *ans)
{
    // Write your code here
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }

    int x = sqrt(n);
    int minimum = INT_MAX;
    if (ans[n] != -1)
    {
        return ans[n];
    }
    for (int i = 1; i <= x; i++)
    {
        minimum = min(minimum, minCount_helper(n - i * i, ans));
    }
    ans[n] = minimum + 1;
    return ans[n];
}
int minCount(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return minCount_helper(n, ans);
}