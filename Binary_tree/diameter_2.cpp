// this is inbuilt class in brakets we mention the data type we wish to use
pair<int, int> diameter(BinaryTreeNode<int> *root) // we will return the pair with max height and max diameter
{
    if (root == NULL) // base case
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> left_ans = (root->left);   // ab wo pair return hua hai jiske pass max height aur diameter hai left subtre ka
    pair<int, int> right_ans = (root->right); // b wo pair return hua haijiske pass max height aur diameter return hua hai right subtree ka
    int lh = left_ans.first;
    int ld = left_ans.second;
    int rh = right_ans.first;
    int rd = right_ans.second;
    int h = 1 + max(lh, rh);
    int d = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = h;
    p, second = d;
    return p;
}