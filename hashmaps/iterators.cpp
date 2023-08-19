#include <iostream>
using namespace std;
#include <unordered_map>
#include <string> //dont forget this

int main()
{
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 1;
    ourmap["abc2"] = 1;
    ourmap["abc3"] = 1;
    ourmap["abc4"] = 1;
    ourmap["abc5"] = 1;
    ourmap["abc6"] = 1;
    unordered_map<string, int>::iterator it = ourmap.begin(); // iterator.begin() will contain starting address of unordered_map
    // very important!!!! unordered map mein starting address kisi bhi element ka ho skta hai kyunki ye map unordered hai
    while (it != ourmap.end())
    {
        cout << "key" << it->first << "value" << it->second << endl; // map mein values are stored in the form of pair
        // it will iterate through address of map
        it++;
    }
    unordered_map<string, int>::iterator it2 = ourmap.find("abc"); // it1 will return iterator of key abc
    // aur uss iterator se aap baacha hua map bhi access kr skte ho
    ourmap.erase(it2);
    ourmap.erase(ourmap.begin(), ourmap.end());

    return 0;
}
// same hi tarika hai ordered map par iterator chalane ka bss farq itna hai ki isme output randomly aaaya aaya aur ordered mein sorted ayega by traversing BST in inorder form