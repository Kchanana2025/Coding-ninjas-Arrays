// O(n)
// O(n)
#include <unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, bool> mp;
    unordered_map<int, int> mp1;
    for (int i = 0; i < n; i++) // setting values corresponding to all keys as false so that we dont visit the visited element again
    {
        mp[i] = false;
    }
    for (int i = 0; i < n; i++) // setting values corresponding to all keys as false so that we dont visit the visited element again
    {
        mp1[arr[i]] = i;
    }
    int Max_length = 0;
    int start_final = 0;
    int final_start_index = 0;
    for (int i = 0; i < n; i++)
    {
        int length = 0;

        if (mp[i] == false)
        {
            int x = arr[i];     // x will help us to find the largest sequence
            int start = arr[i]; // start will keep value of the first element of the largest consecutive sequence
            int index = i;
            while (mp1.count(x) > 0) // this simply means that: is x present in map as a key?it will return 1 if yes and 0 if not.(ofcourse key present hai toh value bhi present hogi hi)
            {
                length++;
                mp[arr[index]] = true;
                x = x + 1;
                if (mp1.count(x) > 0)
                {
                    index = mp1[x];
                }
            }
            // we are check if some elements are present before start
            x = start - 1;
            if (mp1.count(x) > 0)
            {
                index = mp1[x];
            }
            while (mp1.count(x) > 0)
            {
                length++;
                mp[arr[index]] = true;
                start = x;

                x = x - 1;
                if (mp1.count(x) > 0)
                {
                    index = mp1[x];
                }
            }
            if (Max_length < length)
            {
                Max_length = length;
                start_final = start;
                final_start_index = mp1[start];
            }
            else if (Max_length == length)
            {
                if (mp1[start] < final_start_index) // startindex right now is mp1[start]
                {
                    start_final = start;
                    final_start_index = mp1[start];
                }
            }
        }
    }
    vector<int> v;
    v.push_back(start_final);
    v.push_back(start_final + Max_length - 1);
    return v;
}