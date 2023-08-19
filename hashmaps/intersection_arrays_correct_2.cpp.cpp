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
        //  cout<<output[arr2[i]];
        if (output.find(arr2[i]) != output.end())
        {
            cout << arr2[i] << endl;

            if (output[arr2[i]] > 1)
                output[arr2[i]]--;
            else
            {
                output.erase(arr2[i]);
            }
        }
    }
}