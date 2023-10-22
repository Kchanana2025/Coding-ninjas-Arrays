#include <bits/stdc++.h>
int minCount(int n)
{
    // Write your code here
    if (n == 1)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    int x = sqrt(n);
    int minimum = INT_MAX; // min is a predefined keyword isliye hi minimum rakh dia naamvariable ka
    for (int i = 1; i <= x; i++)
    {
        minimum = min(minimum, minCount(n - i * i)); // i^2 is i XOR 2
    }
    return minimum + 1;
}