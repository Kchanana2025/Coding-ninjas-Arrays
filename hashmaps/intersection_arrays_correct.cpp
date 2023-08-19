// time:O(n)+O(n)//dusre loop ka kaam bhi O(n) hai because arr1 mein kitte bhi elements thee bss uhni hi elements ke upar dusre loop mein operation hua hai .therefore O(n) for second loop also.aise isliye kaha maine because time complexity is determined by ki kitne elements by operations hue naki kitne baar loop chala .second loop mein n elements pr O(1) kaam hua hai isliye O(n)
// time:O(n)(explained above)
// space: O(n)
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