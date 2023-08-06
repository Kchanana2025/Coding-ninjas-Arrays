// #include "Binary_tree.h" //nai kia because .cpp mein file mein ye file include krne se phle Binary_tree.h ko include kr lia humne
class BST
{
    // Define the data members
    Binary_tree<int> *root;

    // private functions
    Binary_tree<int> *find_minimum(Binary_tree<int> *root)
    {
        Binary_tree<int> *ans = root;
        if (root->left != NULL)
            ans = find_minimum(root->left);
        return ans;
    }

    Binary_tree<int> *delete_helper(int data, Binary_tree<int> *root)
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
                    // delete root;// delete root call krne se wo apne neeche poore ke poore tree ko delete kr degi aur uske baad root->right return krne ka toh waise hi sense nai bnta
                    // return root->right;
                    Binary_tree<int> *temp = root->right;
                    root->right = NULL;
                    delete root;
                    return temp;
                }
                if (root->right == NULL)
                {
                    Binary_tree<int> *temp = root->left;
                    root->left = NULL;
                    delete root;
                    return temp;
                }
            }
            // jahan upar se kuch connection krna hai wahan root ko return kr dia nai toh agar wahan pr hi connection ho skta h curreny root ke sath toh wahin pr hi kr dia
            else // two children
            {
                Binary_tree<int> *min_node = find_minimum(root->right);
                root->data = min_node->data;

                root->right = delete_helper(min_node->data, root->right); // root->right min_node->right nai rakhna yaha galat ayega ans dry run krke dekhlo

                // 2 children wala case left se min nikalke bhi kr skte
            }
        }
    }
    Binary_tree<int> *insert_helper(int data, Binary_tree<int> *root)
    {
        if (root == NULL)
        {
            Binary_tree<int> *node = new Binary_tree<int>(data);
            root = node;
            return root;
        }
        else if (data > root->data)
        {
            Binary_tree<int> *node = insert_helper(data, root->right);
            root->right = node;
        }
        else
        {
            Binary_tree<int> *node = insert_helper(data, root->left);
            root->left = node;
        }
        return root;
    }
    bool getData_helper(int data, Binary_tree<int> *root)
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
    void print_helper(Binary_tree<int> *root)
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