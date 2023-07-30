// T(n)=T(n/2)+c->O(n)
// T(n)=T(n-1)+c->O(n)
// space:O(h)

// dekho ans ussi smay return krdo jaise hi ans=true hua there is no point ki ans true hone ke baad bhi aap left chk
//  kr rhe right chk kr rhe phir return kr rhe,
// jab false hai ans tab mt return kro tab hr jagah check kro ki kahi aur true aa jaye(kahi aur node present ho) aur jaise hi true aaye tab return kro aur agr true aaye hi nai toh krdo false return
// dhyan se dekho quesn kya mang rha hai smjh aa jayegi ye waali baat
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    else
    {
        bool ans = isNodePresent(root->left, x);
        if (ans == true)
            return true;
        else
        {
            ans = isNodePresent(root->right, x);
            return ans;
        }
    }
}