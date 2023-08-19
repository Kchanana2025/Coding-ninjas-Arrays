// O(n)
// O(n)
#include <unordered_map>
// phle pair nikal rhe h uske baad frequency add rhe h swal visualize kro
int pairSum(int *arr, int n)
{
    unordered_map<int, int> output;
    int pairsum = 0;
    for (int i = 0; i < n; i++)
    {
        int complement = -arr[i];
        if (output.count(complement) > 0)
        {
            pairsum += output[complement];
        }
        output[arr[i]]++;
    }
    return pairsum;
}
