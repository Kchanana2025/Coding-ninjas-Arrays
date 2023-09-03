int minCount(int n)
{
    // base case
    if (n == 1)
    {
        return 1;
    }

    if (n == 0)
    {
        return 0;
    }
    int k = sqrt(n);
    int mini = INT_MAX; // min is a predefined keyword
    for (int i = 1; i <= k; i++)
    {
        int ans = 1 + minCount(n - (i * i)); // i^2 is i XOR 2
        if (mini > ans)
        {
            mini = ans;
        }
    }
    return mini;
}
