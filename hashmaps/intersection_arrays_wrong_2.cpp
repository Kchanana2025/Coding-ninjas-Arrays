
#include <unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m)
{
    unordered_map<int, int> output;
    for (int i = 0; i < m; i++)
        output[arr2[i]]++;

    for (int i = 0; i < n; i++)
    {
        if (output.count(arr1[i]) == 1)
        {
            output[arr1[i]]++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (output[arr2[i]] >= 2)
        {
            cout << arr2[i] << endl;
        }
    }
}