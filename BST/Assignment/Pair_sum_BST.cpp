// O(n+nlogn+n)=O(nlogn)
// O(n)
#include <bits/stdc++.h>
int k = 0;
// we are just storing preorder traversal in an array
void inOrder(BinaryTreeNode<int> *root, int *arr)
{
    if (root == NULL)
        return;

    inOrder(root->left, arr);
    arr[k] = root->data;
    k++;
    inOrder(root->right, arr);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int sum)
{
    int arr[1000000];
    inOrder(root, arr);
    // sort(arr,arr+k);
    int i = 0;
    int j = k - 1;
    while (i < j) // jab tak i jo hai j se chota hai tabhi tak hum ye kaam kr skte hain equal hote hi nikal jana hai because hmien 2 nos ka sum ek value ke barabaar nikalna hai
    {
        if (arr[i] + arr[j] == sum)
        {
            cout << arr[i] << " " << arr[j];
            cout << endl;
            i++;
            j--;
        }
        else if (arr[i] + arr[j] > sum)
        {
            j--;
        }
        else if (arr[i] + arr[j] < sum)
        {
            i++;
        }
    }
}