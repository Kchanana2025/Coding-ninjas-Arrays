#include <limits.h>
TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (root == NULL) // ye krna zaruri hai because segmentation fault ajaega agar root NULL hua toh
        return NULL;
    TreeNode<int> *maximum = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *Max = maxDataNode(root->children[i]); // Max is statically allocated hr iteration ke baad wo deacllocate ho jata hai
        if (maximum->data < Max->data)                       // I was doing this mistake of writing if(root->data<Max->data); ab root toh fix hai lekin maximum  baar baar update ho rha hr children ke data ke according
            maximum = Max;
    }
    return maximum;
}