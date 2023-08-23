// O(n)
// O(n)
#include <unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k)
{
    unordered_map<int, int> mp;
    int count = 0;
    int diff;
    // pairs repeat nai honge dry run krke dekh lo
    if (k != 0)
    {
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;

            // if (k < arr[i])
            // {
            //     diff = (arr[i] - k);
            // }
            // else if (k >= arr[i]) //= kisi mein bhi daaldo chalega
            // {
            //     diff = (arr[i] + k);
            // }
            if (mp.count(arr[i] + k) > 0)
            {
                count = count + mp[arr[i] + k];
            }

            if (mp.count(arr[i] - k) > 0)
            {
                count = count + mp[arr[i] - k];
            }
        }
    }
    else if (k == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (mp.count(arr[i]) > 0)
            {
                count = count + mp[arr[i]];
                // count--; // no need.
            }
            mp[arr[i]]++;
        }
    }

    return count;
}