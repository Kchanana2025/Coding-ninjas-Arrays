#include <vector>
using namespace std;
template <typename T> // hmesha vector ke neeche declare kia kro because #include<vector> is required library for using template
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children; // even if you dont write T it will assume it as T (explaination in notebook)
    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode() // it will be called when you call delete(root) in main();

    {
        for (int i = 0; i < children.size(); i++) // isme apko root->children.size() nai zarurat likhne ki kyunki ye fun root ke lie hi call hua hai (ye function class ke andar hai) toh hamien ye btane ki zarurat nai hai ki object kon hai
        {
            delete (children[i]);
        }
    }
};
