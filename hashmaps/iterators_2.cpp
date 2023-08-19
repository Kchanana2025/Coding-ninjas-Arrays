#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    vector<int>::iterator it = v.begin();
    // offc ye ek order mein hi print honge
    while (it != v.end())
    {
        cout << *it;
        it++;
    }
    vector<int>::iterator it2 = find(v.begin(), v.end(), 1); // it1 will return iterator of key abc
    // aur uss iterator se aap baacha hua map bhi access kr skte ho
    v.erase(it2); // iterator jahan point kr rha hai wo usko delete kr dega
    v.erase(v.begin(), v.end());
    v.erase(it2, it2 + 4); // it2 se it2+3 tak sare delete kr dega .
    // upar wala function unordered map mein sense nai bnaega because it2 ,it2+1,it2+2,it2+3 sath sath toh hoge nai randomly placed honge
    return 0;
}