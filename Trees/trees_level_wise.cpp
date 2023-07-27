#include "vector_use.h"
#include <iostream>
#include <queue>
using namespace std;
// O(n)
// O(n+h)=O(n)//queue ka space
TreeNode<int> *takeinput_level_wise()
{
    int root_data;
    cout << "Enter root data" << endl;
    cin >> root_data;
    TreeNode<int> *root = new TreeNode<int>(root_data);
    queue<TreeNode<int> *> pending_nodes; // sirf wo waali nodes hongi inme jinke hmne children abhi nai puche
    pending_nodes.push(root);
    while (pending_nodes.size() != 0) // ab hr ek pending node ke sath 3 kaam honge children pucho inputlo queue mein daalo connection kro corresponding root ke sath
    {
        int num_child;
        TreeNode<int> *front = pending_nodes.front();
        pending_nodes.pop(); // usi element ko front se lekar ab delete kr dia
        cout << "Enter no of children of " << front->data << endl;
        cin >> num_child;
        for (int i = 0; i < num_child; i++)
        {
            int data;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> data;
            TreeNode<int> *child = new TreeNode<int>(data); // node must be created dyanmicallly taki next iteration
            // mein ye gayab na ho jaye node lekin child pointer is static wo iteration mein deallocate hoke phirse allocate ho rahi hai
            pending_nodes.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}
// O(2n)
// O(n+h)=O(n)
void print_levelwise(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        // when we are taking out something out of queue we are treating it as parent and printing its children and
        // then pushing those children inside queue.When something goes inside queue it is treated as child  and when
        // someting is taken out of queue it is treated like parent because we print its children
        TreeNode<int> *front = pending_nodes.front(); // we accessed first node inside queue
        pending_nodes.pop();                          // node delete kari queue se
        cout << front->data << ":";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            pending_nodes.push(front->children[i]);
        }
        cout << endl;
    }
}
int main()
{
    TreeNode<int> *root = takeinput_level_wise(); // root ko dobara initialize krna hi padhega because wo ek aise function mein initialized hai jiske khtm hoke hi suska scope bhi khtm ho rha hai
    print_levelwise(root);
}