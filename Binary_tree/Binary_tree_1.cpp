#include "Binary_tree.h"
#include <iostream>
using namespace std;
void print(Binary_tree<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data;
    print(root->left);
    print(root->right);
}
int main()
{
    Binary_tree<int> *root = new Binary_tree<int>(1);
    Binary_tree<int> *node2 = new Binary_tree<int>(2);
    Binary_tree<int> *node3 = new Binary_tree<int>(3);
    root->left = node2;
    root->right = node3;
    print(root);
    delete (root);
    return 0;
}
