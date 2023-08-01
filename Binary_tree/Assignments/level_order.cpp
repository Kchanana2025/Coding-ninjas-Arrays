// O(N)//we are accessing all nodes
// O(N/2) ie O(N) at a worst time queue can contain max of N/2 nodes
// i.e kisi particular level pe max N/2 nodes ho skti hain
// dry run the code u will get a clarity
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pending_nodes;
    pending_nodes.push(root);
    pending_nodes.push(NULL);
    while (pending_nodes.size() != 0)
    {
        while (pending_nodes.front() != NULL)
        {
            BinaryTreeNode<int> *x = pending_nodes.front();
            pending_nodes.pop();
            cout << x->data << " ";
            if (x->left != NULL)
                pending_nodes.push(x->left);
            if (x->right != NULL)
                pending_nodes.push(x->right);
        }
        pending_nodes.pop();
        if (pending_nodes.size() == 0) // means all nodes have been traversed and there no need to push null now
            break;                     // or continue
        else
        // we popped it as we have got to know it was NULL and now we can enter endl
        //   then pushed it again because since elements are present in queue(as size!=0) and we have encountered NULL that means one level must have got over so we must push NULL inside the queue
        {
            cout << endl;
            pending_nodes.push(NULL);
        }
    }
}