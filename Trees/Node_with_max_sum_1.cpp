#include <climits>
// O(n)
//  O(h)
template <typename T>
class helper_class // pair is predefined word
{
public:
    int sum;
    TreeNode<T> *Node;
};
helper_class<int> *helper_max_SumNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        helper_class<int> *node = new helper_class<int>(); // khali constructor aise call hota h bracket bhi lgane hote hain khali
        node->sum = INT_MIN;
        node->Node = NULL;
        return node;
    }
    helper_class<int> *node1 = new helper_class<int>(); // I was declaring this node with wrong syntax
    int sum_1 = root->data;
    TreeNode<int> *ans = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum_1 += root->children[i]->data;
    }
    node1->sum = sum_1;
    node1->Node = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        helper_class<int> *pair_ans = helper_max_SumNode(root->children[i]);
        if (pair_ans->sum > node1->sum)
        {
            node1->sum = pair_ans->sum;
            node1->Node = pair_ans->Node;
        }
    }
    return node1;
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    return helper_max_SumNode(root)->Node;
}
