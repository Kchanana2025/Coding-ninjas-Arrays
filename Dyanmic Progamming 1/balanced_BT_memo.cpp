#include <bits/stdc++.h>
using namespace std;
// we are assuming that h>=0
int balanced_BT_helper(int *ans, int h)
{

    if (h == 0 || h == 1) // recursion ka base case tabhi chalega jab dono n ki values 1 return kregi
    //    normally bhi jab root=NULL(or h=0) hota hai tab we say that it is a balanced BT.(jab koi node hi nai hai toh balanced binary tree hai)
    {
        return 1;
    }
    if (ans[h] != -1)
    {
        return ans[h];
    }
    int x = balanced_BT_helper(h - 1);
    int y = balanced_BT_helper(h - 2);
    int answer = x * x + 2 * x * y;
    ans[h] = answer;
    return ans[h];
}
int balanced_BT(int h)
{
    int *ans = new int[h + 1];
    for (int i = 0; i <= h; i++)
    {
        ans[i] = -1;
    }
    return balanced_BT_helper(ans, h);
}
int main()
{
    int n;
    cin >> n;
    balanced_BT(n);
}