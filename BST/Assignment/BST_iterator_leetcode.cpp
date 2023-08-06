// O(1)average ,worst:O(h)
// O(h)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator
{
    stack<TreeNode *> s;
    void pushAll(TreeNode *root)
    {
        TreeNode *node;

        for (node = root; node != NULL; node = node->left)
        {
            s.push(node);
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root); // whenever object of BSTiteraator  class i.e whenever object of BST will be created BSTiterator will be called(dont think that it will be called for all nodes of tree whenever they are created)
    }

    int next()
    {
        TreeNode *x = s.top();
        s.pop();
        pushAll(x->right);
        return x->val;
    }

    bool hasNext()
    {
        return !s.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */