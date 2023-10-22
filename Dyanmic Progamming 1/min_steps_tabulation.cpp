// O(n)
// O(n)(only array)
#include <limits.h>
int countMinStepsToOne_helper(int n, int *output)
{
    output[1] = 0;               // itertively kr rhe hain hum question ko array mein values save krni hai kuch return nai krna
    for (int i = 2; i <= n; i++) // seedha 2 se start krdo mt socho ki n/2 ka value kahan se layenge .the point is n/2 ka value is 1 hi 1 se chota toh hoega nai .toh n=2 ,n=3 ka base case likhne ki zarurat nai hai
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