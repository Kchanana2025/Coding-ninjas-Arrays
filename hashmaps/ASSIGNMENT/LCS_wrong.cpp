// test case
//  7
//  3 7 2 1 9 8 41
//  Your Output
//  1 3

// Expected Output
// 7 9
// iss code ko theek krne ke lie kamien indexes ka track rakhna padhega in hashmap rather than the actual values
#include <unordered_map>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, bool> mp;
    for (int i = 0; i < n; i++) // setting values corresponding to all keys as false so that we dont visit the visited element again
    {
        mp[arr[i]] = false;
    }
    int Max_length = 0;
    int start_final = 0;
    for (int i = 0; i < n; i++)
    {
        int length = 0;
        if (mp[arr[i]] == false)
        {
            int x = arr[i];         // x will help us to find the largest sequence
            int start = arr[i];     // start will keep value of the first element of the largest consecutive sequence
            while (mp.count(x) > 0) // this simply means that: is x present in map as a key?it will return 1 if yes and 0 if not.(ofcourse key present hai toh value bhi present hogi hi)
            {
                length++;
                mp[x] = true;
                x = x + 1;
            }
            // we are check if some elements are present before start
            x = start - 1;
            while (mp.count(x) > 0)
            {
                length++;
                mp[x] = true;
                start = x;
                x = x - 1;
            }
            if (Max_length < length)
            {
                Max_length = length;
                start_final = start;
            }
        }
    }
    vector<int> v;
    v.push_back(start_final);
    v.push_back(start_final + Max_length - 1);
    return v;
}