#include <unordered_map>
string uniqueChar(string str)
{
    unordered_map<char, int> mp;
    string s;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (mp.count(str[i]) > 0)
        {
            continue;
        }
        else
        {
            mp[str[i]]++;
            s += str[i];
        }
    }
    return s;
}