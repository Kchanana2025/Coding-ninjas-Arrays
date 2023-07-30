// my mistakes:didnt include climits,first we need to print minimum then maximum i did reverse
//  if you did it normally it would have code O(n*h) naii kr hi nai paate pair se hi krna tha because do cheezien return krni hai re
//  time: O(n)
//  space:O(h)
#include <utility>
#include <climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) // baar baar jaake preshan mat krow bss ek baar jaake kaam krlo
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = INT_MAX; // first is minmum
        p.second = INT_MIN;
        return p;
    }
    pair<int, int> left_ans = getMinAndMax(root->left);   // it will return pair that will contain min and max from left subtree
    pair<int, int> right_ans = getMinAndMax(root->right); // it will return pair that will contain min and max from right subtree
    int lmin = left_ans.first;
    int lmax = left_ans.second;
    int rmin = right_ans.first;
    int rmax = right_ans.second;
    int ans_min = min(root->data, min(lmin, rmin));
    int ans_max = max(root->data, max(lmax, rmax));
    pair<int, int> p;
    p.first = ans_min;
    p.second = ans_max;
    return p;
}

// #include <climits>
// #include <utility>

// /*
//         The first value of the pair is the minimum value in the tree and
//         the second value of the pair is the maximum value in the tree
// */
// pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
//   // Write your code here
//   // corner case
//   if (root == NULL) {
//     return {INT_MAX, INT_MIN};
//   }

//   pair<int, int> left = getMinAndMax(root->left);
//   pair<int, int> right = getMinAndMax(root->right);

//   // corner case
//   if (left.first == INT_MAX and right.first == INT_MAX and
//       left.second == INT_MIN and right.second == INT_MIN) {
//     return {root->data, root->data};
//   }

//   int curr_MIN = min(left.first, right.first);
//   int curr_MAX = max(left.second, right.second);

//   if (root->data < curr_MIN) {
//     return {root->data, curr_MAX};
//   } else if (root->data > curr_MAX) {
//     return {curr_MIN, root->data};
//   } else {
//     return {curr_MIN, curr_MAX};
//   }
// }