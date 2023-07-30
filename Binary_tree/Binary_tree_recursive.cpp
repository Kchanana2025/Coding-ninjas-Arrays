#include "Binary_tree.h"
#include <iostream>
using namespace std;
// average:T(n)=2T(n/2)+c->O(n)
// worst:T(n)=T(n-1)+c->O(n)
// space:O(h)
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
// average:T(n)=2T(n/2)+c->O(n)
// worst:T(n)=T(n-1)+c->O(n)
// space:O(h)
Binary_tree<int> *takeinput()
{
    int rootdata;
    cout << "ENTER DATA";
    cin >> rootdata;
    if (rootdata == -1) //-1 acts like a terminator ki if u put -1 as a input kahin bhi that means end of nodes left side aur right side mein bhi ye btane ke lie ki input le lia gya hai we enter -1
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
    delete (root); // destructor will be called for all nodes just by writing delete root
    // u can write delete root or delete(root)
    return 0;
}
