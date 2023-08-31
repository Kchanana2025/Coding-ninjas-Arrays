// O(n)
// O(n)+O(n)
#include <iostream>
using namespace std;
int fibo_helper(int *ans, int n)
{

    if (n <= 1)
    {
        return n;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }

    int a = fibo_helper(ans, n - 1);
    int b = fibo_helper(ans, n - 2);
    ans[n] = a + b;
    return ans[n];
}
int fibo(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1; // we have done this taki jab kisi ith value ki zarurat padhe aur hamien check krna ho ki wo phle se hai and then wo -1 nikle toh hm usse use na kr lien balki uss value ko calculate krien
    }
    return fibo_helper(ans, n);
}
int main()
{
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}