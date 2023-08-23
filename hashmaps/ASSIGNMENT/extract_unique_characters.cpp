// O(n)
// O(n)
#include <unordered_map>
string uniqueChar(string str)
{
    unordered_map<char, int> mp;
    string ans;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (mp.count(str[i]) > 0)
        {
            continue;
        }
        else
        {
            mp[str[i]]++;
            ans += str[i];
        }
    }
    return ans;
}