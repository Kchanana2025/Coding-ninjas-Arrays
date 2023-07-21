// O(n)
// O(h)
bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{

    if (root1 == NULL && root2 == NULL)
        return true; // dono khali hain toh same toh hain
    else if (root1 == NULL)
        return false;
    else if (root2 == NULL)
        return false;
    bool ans = true;
    if (root1->data != root2->data)
        return false;
    if (root1->children.size() != root2->children.size()) // agar size check nai kia aur unequal hua size mein par tree 1 ki values tree 2 jaisi hi hai  toh jitni nodes match ho rahi hai usne
    //  check kr lia ki bhyi ho gayi phir manlo tree1 is small toh loop terminate ho jayega aur ans true return kr dega (mtlb ek case bnta hai jisme ye ho skta hai)
    {
        return false;
    }
    for (int i = 0, j = 0; i < root1->children.size(), j < root2->children.size(); i++, j++)
    {
        ans = areIdentical(root1->children[i], root2->children[j]);
        if (ans == false) // or(!ans)
            return false;
    }
    return ans;
}