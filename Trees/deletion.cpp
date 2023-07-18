void deletetree(TreeNode<int> *root)
{
    for (int i = 0; i < children.size(); i++)
    {
        deletetree(root->children[i]);
    }
    delete root;
}
// OR we can destructor see in vector.h which I have pasted here as well
~TreeNode() // it will be called when you call delete(root) in main();

{
    for (int i = 0; i < children.size(); i++) // isme apko root->children.size() nai zarurat likhne ki kyunki ye fun root ke lie hi call hua hai (ye function class ke andar hai) toh hamien ye btane ki zarurat nai hai ki object kon hai
    {
        delete (children[i]);
    }
}
