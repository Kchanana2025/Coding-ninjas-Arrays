// O(n+n)=O(n)
// O(n)
#include <bits/stdc++.h>
int k = 0;
// we are just storing preorder traversal in an array
void preOrder(BinaryTreeNode<int> *root, int *arr)
{
    if (root == NULL)
        return;
    arr[k] = root->data;
    k++;
    preOrder(root->left, arr);
    preOrder(root->right, arr);
}
void pairSum(BinaryTreeNode<int> *root, int sum)
{
    int arr[1000000];
    preOrder(root, arr);
    sort(arr, arr + k);
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
