#include "Binary_tree.h"
#include <iostream>
using namespace std;
Binary_tree<int> *takeinput()
{
    int rootdata;
    cout << "Enter root data";
    cin >> rootdata;
    if (rootdata == -1) // ye function recursive toh hai nai toh last mein as a base case use hoga jab aur nodes nai chahie lekin iska use tab hota hai jab 0 nodes ho tree NULL ho
    {
        return NULL;
    }
    Binary_tree<int> *root = new Binary_tree<int>(rootdata);
    queue<int> *pending_nodes; // contains those nodes jinke children abhi mangne hain aur unke children wapis queue mein push krne hain
    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        Binary_tree<int> *front = pending_nodes.front();
        pending_nodes.pop();
        cout << "Enter data of  left child " << front->data;
        int leftchild;
        cin >> leftchild;
        if (leftchild != 0) // i forgot this
        {
            Binary_tree<int> *leftchild = new Binary_tree<int>(leftchild);
            front->left = leftchild;
            pending_nodes.push(leftchild);
        }

        cout << "Enter data of  right child " << front->data;
        int rightchild;
        cin >> righttchild;
        if (rightchild != 0)
        {
            Binary_tree<int> *rightchild = new Binary_tree<int>(rightchild);
            front->right = rightchild;
            pending_nodes.push(rightchild);
        }
    }
    return root;
}
int main()
{

    return 0;
}