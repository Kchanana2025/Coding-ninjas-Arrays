#include "Binary_tree.h"
#include <iostream>
#include <queue>
using namespace std;

void print_level_wise(Binary_tree<int> *root)
{
    if (root == NULL) // agar khali tree hai sirf tab hi zarurat hai iss condition ki.
        return;

    queue<Binary_tree<int> *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        Binary_tree<int> *front = pending_nodes.front();
        pending_nodes.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data;
            pending_nodes.push(front->left);
        }
        if (front->right != NULL) // if ayega idhar else if nahi
        {
            cout << "R" << front->right->data;
            pending_nodes.push(front->right);
        }
        cout << endl;
    }
}
Binary_tree<int> *takeinput_level_wise()
{
    int rootdata;
    cout << "Enter root data"; // recursive wale solution mein cout<< mein root data we didnt write because that was a recursive function baar baar root dataprint hota sabhi nodes ke lie jabki yaha paar bss ek baar hi root data enter krwana hai
    cin >> rootdata;
    if (rootdata == -1) // ye function recursive toh hai nai toh last mein as a base case use hoga jab aur nodes nai chahie hongi,toh iska use tab hota hai jab 0 nodes ho tree NULL ho (as an edge case)
    {
        return NULL;
    }
    Binary_tree<int> *root = new Binary_tree<int>(rootdata);
    queue<Binary_tree<int> *> pending_nodes; // revise initialization syntax
    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        Binary_tree<int> *front = pending_nodes.front(); // u can use same name for two things but mindfully idhar ek variable hai aur ek function (queue class ka) toh in this case it is fine
        pending_nodes.pop();
        int leftchilddata;
        cout << "enter left child of" << front->data;
        cin >> leftchilddata;
        if (leftchilddata != -1)
        {
            Binary_tree<int> *left = new Binary_tree<int>(leftchilddata);
            front->left = left;
            pending_nodes.push(left);
        }
        int rightchilddata;
        cout << "enter left child of" << front->data;
        cin >> rightchilddata;
        if (rightchilddata != -1)
        {
            Binary_tree<int> *right = new Binary_tree<int>(rightchilddata);
            front->right = right;
            pending_nodes.push(right);
        }
    }
    return root;
}
int main()
{
    Binary_tree<int> *root = takeinput_level_wise();
    print_level_wise(root);
    return 0;
}