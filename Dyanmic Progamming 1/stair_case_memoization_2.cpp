// O(n)
// O(2n)=O(n)
#include <bits/stdc++.h>
using namespace std;
int stair_case(int n, int *ans)
{
    const long long int factor = 1000000007; // ye factor ki value swal mein given hai
    // jab bhi aise questions aate hain jisme baar baar mod krna hota hai taki final ans range se bahar na jaye usme haar sum ke baad mod kia kro.Extra kr dooge chalega kum mt krna.BARE minimum is ki atleast hr sum ke baad mod kro
    int sum = 0;
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    sum += stair_case(n - 1, ans) % factor;
    sum += stair_case(n - 2, ans) % factor;
    sum = sum % factor; // hr sum ke baad %factor krna hota h,taki int ki range se bahar chla jaye
    sum += stair_case(n - 3, ans) % factor;
    sum = sum % factor;
    ans[n] = sum;
    return ans[n] % factor;
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
        t--;
    }
    return 0;
}