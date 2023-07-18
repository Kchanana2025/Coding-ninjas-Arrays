bool isPresent(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;

    if (root->data == x)
        return true;
    for (int i = 0; i < root->children.size(); i++)
    {
        bool ans = isPresent(root->children[i], x);
        if (ans == true) // or if(ans) //agar ek child se true return ho gya hai toh baki children pe jaake check krne ki zarurat hi nai
            // hai moreover aap jaake check kr rhe ho aur na hua 2 baar occurance tab toh false return ho jayega jabki x present tha toh jaise hi x mille return krdo
            return true; // or return ans
    }
    return false;
}