#include "Binary_tree.h"
#include <iostream>
using namespace std;
void print(Binary_tree<int> *root) // intro mein bhi print kia hi tha but this is a better way of printing
{
    if (root == NULL)
        return;
    cout << root->data << ":";
    if (root->left != NULL)
        cout << "L" << root->left->data;
    if (root->right != NULL)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    print(root->left);
    print(root->right);
}
Binary_tree<int> *takeinput()
{
    int rootdata;
    cout << "ENTER DATA";
    cin >> rootdata;
    if (rootdata == -1) //-1 is used like a termination
    {
        return NULL;
    }
    Binary_tree<int> *root = new Binary_tree<int>(rootdata);
    Binary_tree<int> *leftchild = takeinput();
    Binary_tree<int> *rightchild = takeinput();
    root->left = leftchild;
    root->right = rightchild;
    return root;
}
int main()
{
    Binary_tree<int> *root = takeinput();
    print(root);
    delete (root);
    return 0;
}
