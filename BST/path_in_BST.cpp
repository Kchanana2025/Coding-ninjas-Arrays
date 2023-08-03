// O(h)//either node will be last node of left side or last node of right side so max time complexity be O(h)
// O(h)

vector<int> *getPath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL) // tree mein hi kuch nai hai toh vector mein bhi kuch nai hai
        return NULL;
    if (root->data == data)
    {
        ; // we are creating a vector dyanmically whose pointer is v
        // vector<int>* v=new vector<int>(root->data);//wrong way
        vector<int> *v = new vector<int>();
        v->push_back(root->data);
        return v;
    }
    vector<int> *left = getPath(root->left, data);
    if (left != NULL)
    {
        left->push_back(root->data);
        return left;
    }
    else
    {
        vector<int> *right = getPath(root->right, data);
        if (right != NULL)
        {
            right->push_back(root->data); // using arrow because right is a pointer
        }
        else
        {
            return NULL;
        }
    }
}