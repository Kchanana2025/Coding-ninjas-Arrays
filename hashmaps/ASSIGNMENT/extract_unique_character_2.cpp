#include <unordered_map>
string uniqueChar(string str)
{
    // Write your code here
    string ans;
    unordered_map<char, int> mp;
    for (int i = 0; i < str.length(); i++)
    {
        if (mp.count(str[i]) == 0)
        {
            mp[str[i]]++;
            ans += str[i];
        }
    }
    return ans;
}
// dono 1 and 2 same hi hain bss 1 mein ek condition uda di toh 2 bn gya