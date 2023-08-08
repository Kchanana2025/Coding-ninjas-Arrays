void printatDepthK(BinaryTreeNode<int> *root, int K)
{
    if (root == NULL)
        return;
    if (K == 0)
    {
        cout << root->data << endl;
        return;
    }
    printatDepthK(root->left, K - 1);
    printatDepthK(root->right, K - 1);
}
int printkdistanceNode(BinaryTreeNode<int> *root, int node, int k) // returns distance between root andtarget node
{
    if (root == NULL || k < 0)
    {
        return -1;
    }
    else if (root->data == node)
    {
        printatDepthK(root, k);
        return 0;
    }
    int left_distance = printkdistanceNode(root->left, node, k); // left mein at depth k print krke aa gya
    if (left_distance != -1)
    {
        int left_distance_from_root = left_distance + 1; // we need to take care k distance above the node
        if (left_distance_from_root == k)
        {
            cout << root->data;
        }
        else
        {
            int p = k - left_distance_from_root - 1;
            printatDepthK(root->right, p);
        }
        return left_distance_from_root;
    }

    int right_distance = printkdistanceNode(root->right, node, k); // right mein at depth k print krke aa gya
    if (right_distance != -1)
    {
        int right_distance_from_root = right_distance + 1; // we need to take care k distance above the node
        if (right_distance_from_root == k)
        {
            cout << root->data;
        }
        else
        {
            int r = k - right_distance_from_root - 1;
            printatDepthK(root->left, r);
        }
        return right_distance_from_root;
    }
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{

    int x = printkdistanceNode(root, node, k);
}