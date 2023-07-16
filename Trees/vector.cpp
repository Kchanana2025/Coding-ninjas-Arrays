
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector<int> * vp = new vector<int>();
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v[3] = 100; // never ever insert element like this
    // firstly size ka dhyan nai rakha jaega
    // secondly aage push_back krne se ye elemnt overwrite ho jaega

    // dont use [] for inserting elements
    // v[3] = 1002;
    // v[4] = 1234;

    v.push_back(23);
    v.push_back(234);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    cout << v[6] << endl; // garbage print kr deta hai agar element na ho
    cout << v.at(6);      // error deta hai
}