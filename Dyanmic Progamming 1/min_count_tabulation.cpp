// O(n)
// O(n)
#include <bits/stdc++.h>
int minCount(int n)
{
    int *ans = new int[n + 1];
    ans[1] = 1;
    ans[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        int sq = sqrt(i);
        int k = 1;
        int minimum = INT_MAX;
        while (k <= sq)
        {
            int f = 1 + ans[i - k * k];
            minimum = min(minimum, f);
            k++;
        }
        ans[i] = minimum;
    }
    return ans[n];
}
