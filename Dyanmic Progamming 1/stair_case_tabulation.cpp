// time:O(n)
// space:O(n)//array ka size
#include <bits/stdc++.h>
using namespace std;
int stair_case(int n)
{
    int *ans = new int[n + 1];
    const long long int factor = 1000000007;
    int sum = 0;
    if (n < 0)
    {
        return 0;
    }
    ans[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int counter = 0;
        counter += ans[i - 1] % factor;
        counter = counter % factor;
        if (i - 2 >= 0)
        {
            counter += ans[i - 2] % factor;
            counter = counter % factor;
        }
        if (i - 3 >= 0)
        {
            counter += ans[i - 3] % factor;
            counter = counter % factor;
        }
        ans[i] = counter;
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
        int sum = stair_case(n);
        cout << sum << endl;
        t--;
    }
    return 0;
}