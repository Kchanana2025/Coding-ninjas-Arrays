// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int num_nodes(Binary_tree<int> *root)
{

    if (root == NULL) // binary trees mein base case bahot zaruri hota hai unke bina code nai chalega
        return 0;
    int ans = 1;
    int ans1 = num_nodes(root->left);
    int ans2 = num_nodes(root->right);
    ans += ans1 + ans2;
    return ans;
}
//***********************************************************************************************//
int num_nodes(Binary_tree<int> *root)
{

    if (root == NULL)
        return 0;
    int ans = 1;
    return 1 + num_nodes(root->left) + num_nodes(root->right);
}