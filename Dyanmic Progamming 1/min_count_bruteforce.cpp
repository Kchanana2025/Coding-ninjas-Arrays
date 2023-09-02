int min_count(int n)
{
    // base case
    if (n == 1)
    {
        return 1;
    }
    int k = sqrt(n);
    int min = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int ans = 1 + min_count(n - i ^ 2);
        if (min > ans)
        {
            min = ans;
        }
    }
    return min;
}
int main()
{
    int n;
    cin >> n;
    min_count(n);
}