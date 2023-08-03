// o(h)(h=n in worst and h=logn normally)
// O(h)
bool searchInBST(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL) // if element is not present this is the base case
        return false;
    if (root->data == k) // if element is present this is the base case
        return true;
    else if (k < root->data)        // small calc
        searchInBST(root->left, k); // recursive calls
    else if (k > root->data)        // small calc
    {
        searchInBST(root->right, k); // recursive calls
    }
}