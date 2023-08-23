#include <bits/stdc++.h>
using namespace std;
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
        else if (sum == 0)
        {
            length = i + 1;
            if (maxlength < length)
            {
                maxlength = length;
            }
        }
        else
            sum_hashmap[sum] = i; // ye else mein isliye daala hai because agar sum already for ex 5 ho chuka hai toh dobara 5 sum mt daalo kyunki agar tisri baar 5 mil gya toh hm first wale 5 aur 3 rd wale 5 ke beech ka distance jan na chahte hain naki 2 and 3rd
    }
    return maxlength;
}