// O(n)
// O(n)(only array)
#include <limits.h>
int countMinStepsToOne_helper(int n, int *output)
{
    output[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int y = INT_MAX, z = INT_MAX;
        int x = output[i - 1] + 1; // isko toh zarurat nai hai m
        if (i % 2 == 0)
        {
            y = output[i / 2] + 1;
        }
        if (i % 3 == 0)
        {
            z = output[i / 3] + 1;
        }
        int ans = min(x, min(y, z));
        output[i] = ans;
    }
    return output[n];
}
int countStepsToOne(int n)
{
    int *output = new int[n + 1];
    return countMinStepsToOne_helper(n, output);
}