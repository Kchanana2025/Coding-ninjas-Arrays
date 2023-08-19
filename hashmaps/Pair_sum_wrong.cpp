// ye wrong kyu hai nai smjh aa rha

#include <unordered_map>
#include <limits.h>

int factorial(int n)
{
    return (n <= 1) ? 1 : n * factorial(n - 1);
}
int pairSum(int *arr, int n)
{
    unordered_map<int, int> output;

    for (int i = 0; i < n; i++)
    {
        output[arr[i]]++;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (output[0] > 0)
        {
            int freq = output[arr[i]];
            count = factorial(freq) / (2 * factorial(freq - 2));
            output[0] = INT_MIN;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (output.count(-arr[i]) > 0)
        {
            int freq = output[arr[i]];
            int freq_1 = output[-arr[i]];
            int temp = freq * freq_1;
            output[arr[i]] = 0;
            output[-arr[i]] = 0;
            count += temp;
        }
    }

    return count;
}