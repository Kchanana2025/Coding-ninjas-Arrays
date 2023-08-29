// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    vector<int> j(5); // vector of size 3 all 0s
    vector<int> j[5]; // array of 5 vectors
    for (int i = 0; i < j.size(); i++)
    {
        cout << j[i] << ' ';
    }
    cout << endl;
    vector<int> v({1, 2, 3, 4, 5});
    // v.push_back({2,3}); doesnt work(pair banana padhega)
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    return 0;
}