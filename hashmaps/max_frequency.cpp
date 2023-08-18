#include <unordered_map>
#include <limits.h>
int highestFrequency(int arr[], int n)
{
    unordered_map<int, int> output;
    for (int i = 0; i < n; i++)
    {
        if (output.count(arr[i]) == 1) // output.count either eeturns 0 or 1 (if key has some value then 1 if key doesnt have a value then return 0)
        {
            output[arr[i]]++;
        }
        else
        {
            output[arr[i]] = 1;
        }
    }
    int max = INT_MIN;
    int index = 0;
    for (int i = 0; i < output.size(); i++) // isko bhi upar wale loop mein hi daalke kr skte thee
    {

        if (max < output[arr[i]])
        {
            max = output[arr[i]];
            index = arr[i];
        }
    }
    return index;
}