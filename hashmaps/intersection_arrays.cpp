// all test cases are passing but there are 2 mistakes in this code
// eg arr1:
// 2 1 2 4
// arr2:
// 1 2 3
// firstly output is not printed in order of array 2 and secondly mp[arr[i]]>0 must also be checked in first if condition becuase 2 is printed twice and it should be printed once
void printIntersection(int arr1[], int arr2[], int n, int m)
{
    // Write your code here
    unordered_map<int, int> mp;
    if (n > m)
    {
        for (int i = 0; i < m; i++)
            mp[arr2[i]]++;
        for (int i = 0; i < n; i++)
        {
            if (mp.count(arr1[i]) == 1)
            {
                cout << arr1[i] << endl;
                mp[arr1[i]]--;
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
            mp[arr1[i]]++;
        for (int i = 0; i < m; i++)
        {
            if (mp.count(arr2[i]) == 1 && mp[arr2[i]] > 0)
            {
                cout << arr2[i] << endl;
                mp[arr2[i]]--;
            }
        }
    }
}