#include <iostream>
using namespace std;
#include <queue>
void ksortedArray(int *input, int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }
    int j = 0;                  // j maintains the  index of the sorted array
    for (int i = k; i < n; i++) // this loop makes sure that all elements away from k-1 distance from the jth index element are into the heap
    {
        input[j] = pq.top(); // j pr jo value pri hogi wo lost nai hogi kyunki already wo value heap ke andar hai
        pq.pop();
        pq.push(input[i]);
        j++;
    } // only n-k elements get sorted from this loop

    // to sort further k elements we require another loop
    while (pq.size() != 0)
    {
        input[j] = pq.top();
        pq.pop();
        j++;
    }
}
int main()
{
    int input[] = {10, 12, 6, 7, 9};
    int k = 3;
    ksortedArray(input, 5, k);
    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }
    return 0;
}