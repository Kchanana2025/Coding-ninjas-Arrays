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

int main()
{
    TreeNode<int> *root = takeinput(); // root ko dobara initialize krna hi padhega because wo ek aise function mein initialized hai jiske khtm hoke hi suska scope bhi khtm ho rha hai
    printtree(root);
}