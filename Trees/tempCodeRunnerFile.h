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
};