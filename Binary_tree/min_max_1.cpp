// bahot hi lambe tarike se kia hai seedha hi root left aur right jo min hai usko min kehdo jo max hai usko max kehdo
// pr phir bhi padhlo because iske corner case mein(ki iski need kya hai) aur last ke if else(ki ek true hone pe return kyu kr dia) mein i got confused
#include <climits>
#include <utility>

/*
        The first value of the pair is the minimum value in the tree and
        the second value of the pair is the maximum value in the tree
*/
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{
    // Write your code here
    // corner case
    if (root == NULL)
    {
        return {INT_MAX, INT_MIN};
    }

    pair<int, int> left = getMinAndMax(root->left);
    pair<int, int> right = getMinAndMax(root->right);

    if (left.first == INT_MAX and right.first == INT_MAX and // corner case
        left.second == INT_MIN and right.second == INT_MIN)
    {
        return {root->data, root->data};
    }

    int curr_MIN = min(left.first, right.first);
    int curr_MAX = max(left.second, right.second);
    // koi bhi condition true hone pe isliye return kr rhe hain kyunki koi do consitions sath mein sach ho ni skti root ka data bda bhi hoga max se it is not possiblr
    if (root->data < curr_MIN)
    {
        return {root->data, curr_MAX};
    }
    else if (root->data > curr_MAX)
    {
        return {curr_MIN, root->data};
    }
    else
    {
        return {curr_MIN, curr_MAX};
    }
}