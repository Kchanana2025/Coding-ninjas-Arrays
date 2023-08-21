#include <unordered_map>
string uniqueChar(string str)
{
    string ans;
    unordered_set<char> charSet;
    // we are using set plz sirf keys hai values nai hain
    for (char ch : str) // character is traversring over string
    {
        if (charSet.find(ch) == charSet.end())
        {
            ans.push_back(ch); // puch_back function can also be used in case of string
            charSet.insert(ch);
        }
    }
    return ans;
}
//.find() (in map or set)
// The function returns an iterator which points to the element which is searched in the set container.
//  If the element is not found, then the iterator points to the position just after the last element in the set.
