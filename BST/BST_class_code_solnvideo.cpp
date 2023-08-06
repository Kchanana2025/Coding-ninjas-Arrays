#include <iostream>
using namespace std;
#include "Binary_tree.h"
#include "BST_class_code_solnvideo_.h"
int main()
{
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);
    b.print();
    b.remove(10);
    b.print();
}
