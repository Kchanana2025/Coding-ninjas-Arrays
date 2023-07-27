// O(n)
// O(h)
template <typename T>
class helper
{
public:
    TreeNode<T> *largest;
    TreeNode<T> *secondlargest;
    helper(TreeNode<int> *largest, TreeNode<int> *secondlargest)
    {
        this->largest = largest;
        this->secondlargest = secondlargest;
    }
};

helper<int> *getSecondLargest_helper(TreeNode<int> *root)
{
    if (root == NULL)
    { // wese toh I didnt know entire code but I didnt know this as well because secnondlargest node will not exist in 1 node and 0 nodes
        //|| root->children.size()==0 maine upar wali condition mein ye lga dia tha jo super paap hai largets NULL thodi hai bhai recursive calls jab ho rhi thi aur leaf node ajata tha toh jadbad ho jati thi null null return hone ki vjah se
        helper<int> *node1 = new helper<int>(NULL, NULL);
        return node1;
    }
    helper<int> *ans = new helper<int>(root, NULL);
    for (int i = 0; i < root->children.size(); i++)
    {
        helper<int> *childans = getSecondLargest_helper(root->children[i]);

        if (childans->largest->data > ans->largest->data)
        {
            if (childans->secondlargest == NULL)
            {
                ans->secondlargest = ans->largest;
                ans->largest = childans->largest;
            }
            else
            {
                // ans->secondlargest=NULL hone se hamiien koi frak nai padhta
                if (ans->largest->data > childans->secondlargest->data)
                {
                    ans->secondlargest = ans->largest;
                    ans->largest = childans->largest;
                }
                else
                {
                    ans->secondlargest = childans->secondlargest;
                    ans->largest = childans->largest;
                }
            }
        }
        else
        {
            if (ans->largest->data != childans->largest->data && (ans->secondlargest == NULL || childans->largest->data > ans->secondlargest->data))
            {
                ans->secondlargest = childans->largest;
            }
        }
    }
    return ans;
}
TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    helper<int> *ans = getSecondLargest_helper(root);
    return ans->secondlargest;
}
