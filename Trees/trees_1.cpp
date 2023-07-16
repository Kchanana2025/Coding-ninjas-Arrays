#include "vector_use.h"
#include <iostream>
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
    TreeNode<int> *root = new TreeNode<int>(1); // jaise link list mein node dyanmically bnate thee waise hi socho bss jaha pr template ki whaj se <int> extra btana padh rha hai
    TreeNode<int> *n1 = new TreeNode<int>(2);
    TreeNode<int> *n2 = new TreeNode<int>(3);
    root->children.push_back(n1);
    root->children.push_back(n2);
    printtree(root);
}