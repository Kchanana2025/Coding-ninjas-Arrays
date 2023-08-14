
#include <queue>
int kthLargest(int *arr, int n, int k)
{
    // Write your code here
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i < n; i++)
    {
        int minimum = pq.top();
        if (minimum < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
    // OR
    // NO need to find minimum it is the topmost element of the min priority queue
    //  vector<int> v;
    //    for(int i=0;i<k;i++){
    //        v.push_back(pq.top());//just returns in minimum element
    //        pq.pop();//deletes the minimum element
    //  }

    //     int   kthlargest=v[0];//kth largest is the smallest element in the vector
    //     for(int i=1;i<k;i++){

    //         if(v[i]<kthlargest){
    //             kthlargest=v[i];
    //         }
    //     }
    // return kthlargest;
}