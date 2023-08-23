// isme jo galti hai wo correct code mein theek krdi hai
#include <bits/stdc++.h>
int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    unordered_map<int, int> sum_hashmap; // store sum and indexes
    int sum = 0;
    int maxlength = 0;
    int length = 0;
    for (int i = 0; i < n; i++)
    {

        sum += arr[i];
        if (sum_hashmap.count(sum) > 0)
        {
            length = i - sum_hashmap[sum];
            if (maxlength < length)
            {
                maxlength = length;
            }
        }

        sum_hashmap[sum] = i; // hm ye upar wale for loop ke end mein kr rhe hain because hm chahate hain ki wo koi aur sum ko detect kre hmko hi detect na krle

        if (sum == 0)
        {

            length = i + 1;
            if (maxlength < length)
            {
                maxlength = length;
            }
        }
    }
    return maxlength;
}