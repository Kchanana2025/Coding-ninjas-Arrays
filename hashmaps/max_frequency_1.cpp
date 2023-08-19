// O(n)
// O(n)
// correction of max_frequency_wrong
#include <map>
#include <limits.h>
int highestFrequency(int arr[], int n)
{
    map<int, int> output;
    for (int i = 0; i < n; i++)
        output[arr[i]]++;

    int maxFreq = INT_MIN;
    int element = 0;
    map<int, int>::iterator it = map.begin();
    while (it != map.end())
    {
        if (maxFreq < it->second)
        {
            maxFreq = it->second;
            element = it->first;
        }
    }
    return element;
}
