/**********************************************************

    Following is the Binary Tree Node class structure

    template <typename T>
    class BinaryTreeNode {
        public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

class BST
{
    // Define the data members
    BinaryTreeNode<int> *root;

    // private functions
    BinaryTreeNode<int> *find_minimum(BinaryTreeNode<int> *root)
    {
        if (root->left != NULL)
            find_minimum(root->left);
        return root;
    }

    BinaryTreeNode<int> *delete_helper(int data, BinaryTreeNode<int> *root)
    {

        if (root == NULL)
        {
            return root;
        }
        if (data > root->data)
        {
            root->right = delete_helper(data, root->right);
        }
        else if (data < root->data)
        {
            root->left = delete_helper(data, root->left);
        }
        else
        {
            if (root->left == NULL && root->right == NULL) // leaf node
            {
                delete root;
                return NULL;
            }
            else if (root->left == NULL || root->right == NULL) // node with 1 child
            {
                if (root->left == NULL)
                {
                    return root->right;
                }
                if (root->right == NULL)
                {
                    return root->left;
                }
            }
            else // two children
            {
                BinaryTreeNode<int> *min_node = find_minimum(root->right);
                //  cout<<min_node->data;
                root->data = min_node->data;
                // cout<<root->data;
                // cout<<root->left->data;
                root->right = delete_helper(min_node->data, min_node); // root->right nai kr rakha tha maine ye mistake tha

                // 2 children wala case left se min nikalke bhi kr skte
            }
        }
    }
    BinaryTreeNode<int> *insert_helper(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
            root = node;
            return root;
        }
        else if (data > root->data)
        {
            BinaryTreeNode<int> *node = insert_helper(data, root->right);
            root->right = node;
        }
        else
        {
            BinaryTreeNode<int> *node = insert_helper(data, root->left);
            root->left = node;
        }
        return root;
    }
    bool getData_helper(int data, BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return false;

        if (root->data == data)
            return true;
        else if (data < root->data)
        {
            return getData_helper(data, root->left);
        }
        else
        {
            return getData_helper(data, root->right);
        }
    }
    void print_helper(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return;

        cout << root->data << ":";
        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << ",";
        }
        if (root->right != NULL)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        print_helper(root->left);
        print_helper(root->right);
    }

public:
    BST()
    {
        // Implement the Constructor
        root = NULL;
    }

    /*----------------- Public Functions of BST -----------------*/

    void remove(int data)
    {
        // Implement the remove() function
        root = delete_helper(data, root);
    }

    void print()
    {
        // Implement the print() function
        print_helper(root);
    }

    void insert(int data)
    {
        // Implement the insert() function
        root = insert_helper(data, root);
    }

    bool search(int data)
    {
        // Implement the search() function
        return getData_helper(data, root);
    }
};