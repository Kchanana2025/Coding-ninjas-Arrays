// O(n)
// O(n)
// correction of max_frequency_wrong
#include <map>
#include <limits.h>
#include <iostream>
using namespace std;
int highestFrequency(int arr[], int n)
{
    map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    int maxFreq = INT_MIN;
    int element = 0;

    map<int, int>::iterator it = freq.begin();
    while (it != freq.end())
    {
        if (maxFreq < it->second)
        {
            maxFreq = it->second;
            element = it->first;
        }
        it++;
    }
    return element;
}