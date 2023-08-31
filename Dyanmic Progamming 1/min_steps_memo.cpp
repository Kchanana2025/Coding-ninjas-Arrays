int countMinStepsToOne_helper(int n, int *output)
{
    int x, y = INT_MAX, z = INT_MAX;
    //  base case
    if (n == 1)
    {
        return 0;
    }
    if (output[n] != -1)
    {
        return output[n];
    }

    x = countMinStepsToOne(n - 1);

    if (n % 2 == 0)
    {
        y = countMinStepsToOne(n / 2);
    }
    if (n % 3 == 0)
    {
        z = countMinStepsToOne(n / 3);
    }
    int ans = min(x, min(y, z));
    output[n] = ans + 1;
    return output[n];
}
int countMinStepsToOne(int n)
{
    int *output = new int[n + 1];
    return countMinStepsToOne_helper(n, output);
}
