#include <unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m)
{
    unordered_map<int, int> output;
    for (int i = 0; i < n; i++)
    {
        output[arr1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (output.find(arr2[i]) != output.end())
        {
            cout << arr2[i] << endl;
            output[arr2[i]]--;
        }
        if (output[arr2[i]] == 0)
        {
            output.erase(arr2[i]);
        }
    }
}