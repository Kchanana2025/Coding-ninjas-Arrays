// O(n)
// O(n)+O(n)(call stack and array)
// memoization
int countMinStepsToOne_helper(int n, int *output)
{
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    //  base case
    if (n == 1)
    {
        return 0;
    }
    if (output[n] != -1)
    {
        return output[n];
    }

    x = countMinStepsToOne_helper(n - 1, output);

    if (n % 2 == 0)
    {
        y = countMinStepsToOne_helper(n / 2, output);
    }
    if (n % 3 == 0)
    {
        z = countMinStepsToOne_helper(n / 3, output);
    }
    int ans = min(x, min(y, z));
    output[n] = ans + 1;
    // cout<<output[n]<<" ";
    return output[n];
}
int countMinStepsToOne(int n)
{
    int *output = new int[n + 1];
    for (int i = 0; i <= n; i++) // hm apne output array ko kisi bhi value se initially set kr skte thee provided wo value answer ka part nai honi chahie eg -1 kabhi bhi no of steps ke barabar nai ho skta
    {
        output[i] = -1;
    }
    return countMinStepsToOne_helper(n, output);
}
