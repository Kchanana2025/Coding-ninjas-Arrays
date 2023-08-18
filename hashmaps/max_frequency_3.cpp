#include <unordered_map>
#include <limits.h>
int highestFrequency(int arr[], int n)
{
    int max = INT_MIN;
    int element = 0;
    unordered_map<int, int> output;
    for (int i = n - 1; i >= 0; i--)
    {
        output[arr[i]]++; // by default value 0 hi manta h wo ,toh wo usme ++ krdega
        if (max <= output[arr[i]])
        {
            max = output[arr[i]]; // syores maximum frequency
            element = arr[i];     // store the element whose frequency is maximum
        }
    }
    return element;
}