// O(n)
// O(h)*2
#include <stack>
void push_next_minimum(stack<BinaryTreeNode<int> *> &inOrder, int &visited_nodes, BinaryTreeNode<int> *x) // koi function banana hai toh jis jis function mein call kr rhe ho uske bahar bnao
{
    BinaryTreeNode<int> *x1 = x;
    s1.pop();
    visited_nodes++;
    if (x->right != NULL)
    {
        s1.push(x->right);
        x = x->right;
        x = x->left;
        while (x != NULL)
        {
            s1.push(x);
            x1 = x;
            x = x->left;
        }
    }
}
void push_next_maximum(stack<BinaryTreeNode<int> *> &reverseinOrder, int &visited_nodes, BinaryTreeNode<int> *y)
{
    BinaryTreeNode<int> *y1 = y;
    reverseinOrder.pop();
    visited_nodes++;
    if (y->left != NULL)
    {
        reverseinOrder.push(y->left);
        y = y->left;
        y = y->right;
        while (y != NULL)
        {
            reverseinOrder.push(y);
            y = y->right;
        }
    }
}

int count_nodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int count = 1;
    count += count_nodes(root->left); //+ aur = ke beeche space nai honi cahahie
    count += count_nodes(root->right);
    return count;
}
void printNodesSumToS(BinaryTreeNode<int> *root, int sum)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    stack<BinaryTreeNode<int> *> inOrder;        // to store inorder traversal
    stack<BinaryTreeNode<int> *> reverseinOrder; // to store reverse inorder traversal
    int counter = count_nodes(root);
    int visited_nodes = 0;

    BinaryTreeNode<int> *node = root;
    while (node != NULL)
    {
        inOrder.push(node);
        node = node->left;
    }
    node = root;
    // root dono stacks mein daalega .why? dry run krke dekhlo
    while (node != NULL)
    {
        reverseinOrder.push(node);
        node = node->right;
    }
    //    cout<<"heloo";
    //    cout<<visited_nodes;
    //    cout<<counter;
    while (visited_nodes < counter - 1)
    {
        // cout<<"hey";
        BinaryTreeNode<int> *x = inOrder.top();
        BinaryTreeNode<int> *y = reverseinOrder.top();

        if (x->data + y->data == sum)
        {
            cout << x->data << " " << y->data;
            cout << endl;
            push_next_minimum(inOrder, visited_nodes, x);
            push_next_maximum(reverseinOrder, visited_nodes, y);
        }
        else if (x->data + y->data > sum)
        {

            push_next_maximum(s2, visited_nodes, y);
        }
        else if (x->data + y->data < sum)
        {

            push_next_minimum(inOrder, visited_nodes, x);
        }
    }
}