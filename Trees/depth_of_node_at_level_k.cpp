void print_at_level_k(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->data;
    }
    else
    // hmne idhar else isliye likha hai because neeche ke children mein toh k depth/level wala node mil nai skta ab
    //  ek baar print ho gya hai toh ab jab function return hoga tab hi level k wali nodes milengi
    {
        print_at_level_k(root->children[i], k - 1);
    }
}