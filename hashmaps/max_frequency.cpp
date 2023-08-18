#include <unordered_map>
#include <limits.h>
int highestFrequency(int arr[], int n)
{
    unordered_map<int, int> output;
    for (int i = 0; i < n; i++)
        output[arr[i]]++;

    int maxFreq = INT_MIN;
    int element = 0;
    for (int i = 0; i < output.size(); i++) // very good approach
    {

        if (maxFreq < output[arr[i]])
        {
            maxFreq = output[arr[i]];
            element = arr[i];
        }
    }
    return element;
}
