void zigZagOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
#include <stack>
    stack<BinaryTreeNode<int> *> s; // class ke sath template ke lie data type btao and then variable ka naam btao
    int level = 1;
    queue<BinaryTreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    while (pending_nodes.size() != 0)
    {
        if (level % 2 != 0)
        {
            BinaryTreeNode<int> *x = pending_nodes.front();
            pending_nodes.pop();
            cout << x->data;
            if (x->left != NULL)
            {
                pending_nodes.push(x->left);
            }
            if (x->right != NULL)
            {
                pending_nodes.push(x->right);
            }
        }
        else
        {
            if (x->left != NULL)
            {
                s.push(x->left);
            }
            if (x->right != NULL)
            {
                s.push(x->right);
            }
        }
    }
    while (s.size() != 0)
    {
        BinaryTreeNode<int> *x = s.front();
        s.pop();
        if ()
            if (x->left != NULL)
            {
                pending_nodes.push(x->left);
            }
        if (x->right != NULL)
        {
            pending_nodes.push(x->right);
        }
    }
}