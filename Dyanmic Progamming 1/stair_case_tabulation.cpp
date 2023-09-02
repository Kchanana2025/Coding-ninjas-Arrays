// O(n)
// O(n)
#include <bits/stdc++.h>
using namespace std;
int stair_case(int n, int *ans)
{
    const long long int factor = 1000000007;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 4;
    for (int i = 4; i <= n; i++)
    {
        ans[i] = ((ans[i - 1] + ans[i - 2]) % factor + ans[i - 3]) % factor;
    }
    return ans[n];
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
        stair_case(n, ans);
        cout << ans[n] << endl;
        delete ans;
        t--;
    }
    return 0;
}
