#include <iostream>
#include <unordered_map>
using namespace std;
vector<int> remove_duplicates(int *arr, int n)
{
    vector<int> output;
    unordered_map<int, bool> helper;
    for (int i = 0; i < n; i++)
    {
        if (helper.count(arr[i]) > 0)
        {
            continue;
        }
        else
        {
            helper[arr[i]] = true;
            output.push_back(arr[i]); // store unique values in vector
        }
    }
    return output;
}
int main()
{
    int arr[] = {1, 4, 2, 3, 4, 5, 6};
    vector<int> output = remove_duplicates(arr, n);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i];
    }

    return 0;
}