#include <iostream>
using namespace std;
#include <unordered_map>
int main()
{
    unordered_map<string, int> ourmap;
    // insert or update(if there is value corresponding to a particular key and u wish to change that value just insert that value corrsponding that key previous value will get replaced)
    pair<string, int> p("abc", 1);
    ourmap.insert(p);
    // or
    ourmap["def"] = 2;
    // find or access
    // if the value corrsponding to a particular key is present in the map it will be printed
    cout << ourmap["abc"] << endl;
    cout << ourmap.at("abc") << endl;
    // if the value corrsponding to a particular key is not  present in the map then:
    // by using at it will throew error
    cout << ourmap.at("ghi");
    // by using [] it will insert a default value i.e 0 and then print it
    cout << ourmap["ghi"];

    if (ourmap.count("ghi") > 0) // to check the presence that weather a value present for a particular key or not
    {
    }
    // size function
    cout << "size:" << ourmap.size();

    // erase
    ourmap.erase("ghi");

    return 0;
}