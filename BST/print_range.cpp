// O(n)
// O(h)

void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    // Write your code here
    if (root == NULL)
        return;
    if (root->data >= k1 && root->data <= k2) // this condition includes 3 cases :element = x or =y or <x & >y tino mein koi bhi true hogi toh it will work
    // think if a element is =x it will be less than y definatley ya phir if element is equal to y it will be definatlry greater than x aur koi element beech mein hua toh usko toh kya hi explain krna hai
    {

        elementsInRangeK1K2(root->left, k1, k2);
        cout << root->data << " "; // ye beech mein aana tha dono recursive calls ke than was my mistake
        elementsInRangeK1K2(root->right, k1, k2);
    }

    else if (root->data > k2) // root->data is greater than maximum no point going on right
    {
        elementsInRangeK1K2(root->left, k1, k2);
    }
    else if (root->data < k1) // root->data is less than the minimum no point goin on left
    {
        elementsInRangeK1K2(root->right, k1, k2);
    }
}