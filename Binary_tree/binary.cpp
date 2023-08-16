#include "binary_tree.h"
#include <queue>
#include <iostream>
using namespace std;
Binary_tree<int> *takeinput()
{
    int rootdata;
    cout << "enter root data";
    cin >> rootdata;
    if (rootdata == -1) // as a edge case
        return;
    Binary_tree<int> *root = new Binary_tree<int>(rootdata);
    queue<Binary_tree<int> *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        Binary_tree<int> *front = pending_nodes.front();
        pending_nodes.pop();
        int leftchild;
        cout << "enter left child";
        cin >> leftchild;
        if (leftchild != -1)
        {
            Binary_tree<int> *left_side = new Binary_tree<int>(leftchild);
            front->left = left_side;
            pending_nodes.push(left_side);
        }
        int rightchild;
        cout << "enter left child";
        cin >> rightchild;
        if (rightchild != -1)
        {
            Binary_tree<int> *right_side = new Binary_tree<int>(rightchild);
            front->left = right_side;
            pending_nodes.push(right_side);
        }
    }
}
int main()
{
    takei
}
