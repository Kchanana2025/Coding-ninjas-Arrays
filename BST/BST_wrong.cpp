void insert(int data, Binary_tree<int> *root)
{
    if (root == NULL)
        return;
    if (data < root->data && root->left == NULL)
    {
        Binary_tree<int> *node = new Binary_tree<int>(data);
        root->left = node;
    }
    if (data >= root->data && root->right == NULL)
    {
        Binary_tree<int> *node = new Binary_tree<int>(data);
        root->right = node;
    }
    else if (data >= root->data)
    {
        insert(data, root->right);
    }
    else
    {
        insert(data, root->left);
    }
}
