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
    pending_nodes.push(root);                // contains those nodes jinke children abhi mangne hain aur unke children wapis queue mein push krne hain
    while (pending_nodes.size() != 0)
    {
        Binary_tree<int> *front = pending_nodes.front(); // u can use same name for two things but mindfully idhar ek variable hai aur ek function (queue class ka) toh in this case it is fine
        pending_nodes.pop();
        int leftchilddata;
        cout << "enter left child of" << front->data << endl;
        cin >> leftchilddata;
        cout << endl;
        if (leftchilddata != -1)
        {
            Binary_tree<int> *left = new Binary_tree<int>(leftchilddata);
            front->left = left;
            pending_nodes.push(left);
        }
        int rightchilddata;
        cout << "enter right child of" << front->data << endl;
        cin >> rightchilddata;
        cout << endl;
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
    // cout << num_nodes(root);
    return 0;
}

// for takeinput level wise

// The given code is used to take input for a binary tree level-wise and returns the root of the binary tree. Let's analyze the time and space complexity of this code:

// Time Complexity:
// The code uses a while loop that runs as long as there are elements in the queue (pending_nodes). For each node, it takes constant time to read its data and create its left and right children (if they exist). Since each node is processed once, the time complexity is proportional to the number of nodes in the binary tree, which is O(n), where 'n' is the number of nodes in the tree.

// Space Complexity:
// The code uses a queue (pending_nodes) to keep track of nodes whose children are yet to be created. The maximum number of elements that can be in the queue at any point during the execution of the code is the maximum number of nodes at any level of the binary tree. In a balanced binary tree, the maximum number of nodes at any level would be half of the total number of nodes. Hence, the maximum size of the queue would be O(n/2) = O(n).

// Additionally, the code uses space for creating Binary_tree nodes. The space required for creating nodes is proportional to the number of nodes in the binary tree, which is O(n).

// Overall, the space complexity is O(n) + O(n) = O(n).

// for printing levelwise:
//  O(n)each node is processed once
//  O(n)queue's space