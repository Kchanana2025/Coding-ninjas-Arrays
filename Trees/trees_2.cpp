#include "vector_use.h"
#include <iostream>
#include <queue>
using namespace std;
void printtree(TreeNode<int> *root)
{
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    } // pehli node hmne print krdi baki ki recursion kr dega
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printtree(root->children[i]);
    }
}
TreeNode<int> *takeinput() // we will return head of the tree so we set the return type as TreeNode *
{
    int rootdata;
    int n;
    cin >> rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    cout << "Enter the no of children of" << rootdata << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *root_child = takeinput();
        root->children.push_back(root_child);
    }
    return root;
}
TreeNode<int> *takeinput_level_wise()
{
    int root_data;
    cout << "Enter root data";
    TreeNode<int> *root = new TreeNode<int>(root_data);
    queue<TreeNode<int> *> pending_nodes; // sirf wo waali nodes hongi inme jinke hmne children abhi nai puche
    pending_nodes.push(root);
    while (pending_nodes.size() != 0) // ab hr ek pending node ke sath 3 kaam honge children pucho inputlo queue mein daalo connection kro corresponding root ke sath
    {
        int num_child;
        TreeNode<int> *front = pending_nodes.front();
        pending_nodes.pop(); // usi element ko front se lekar ab delete kr dia
        cout << "Enter no of children of" << front->data << endl;
        cin >> num_child;
        for (int i = 0; i < num_child; i++)
        {
            int data;
            cin >> data;
            TreeNode<int> *child = new TreeNode<int>(data); // it must be created dyanmicallly taki next iteration mein ye gayab na ho jaye
            pending_nodes.push(child);
            root->children.push_back(child);
        }
    }
}
int main()
{
    TreeNode<int> *root = takeinput(); // root ko dobara initialize krna hi padhega because wo ek aise function mein initialized hai jiske khtm hoke hi suska scope bhi khtm ho rha hai
    printtree(root);
}