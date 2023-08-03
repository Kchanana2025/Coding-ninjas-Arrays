// O(n)better time complexity T(n)=T(n/2)+k
// O(h)
#include <climits>
class isBSTreturn
{
public:
    // taki class ke bahar isBST function access kr ske in variables ko
    bool isBST;
    int minimum;
    int maximum;
};
isBSTreturn isBST_helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        isBSTreturn output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }
    isBSTreturn left_data = isBST_helper(root->left);
    isBSTreturn right_data = isBST_helper(root->right);
    bool lef = left_data.isBST;
    int Lmin = left_data.minimum;
    int Lmax = left_data.maximum;
    int Rmin = right_data.minimum;
    int Rmax = right_data.maximum;
    bool rig = right_data.isBST;
    bool ans = left_data.isBST && right_data.isBST && Lmax < root->data && Rmin >= root->data; // right pe equal hona allowed hai for this swal
    int ans_min = min(root->data, min(Lmin, Rmin));
    int ans_max = max(root->data, max(Lmax, Rmax));
    isBSTreturn output;
    output.isBST = ans;
    output.minimum = ans_min;
    output.maximum = ans_max;
    return output;
}
bool isBST(BinaryTreeNode<int> *root)
{
    isBSTreturn x = isBST_helper(root);
    return x.isBST;
}
