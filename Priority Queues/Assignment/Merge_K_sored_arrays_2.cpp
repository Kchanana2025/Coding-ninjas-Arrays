#include <vector>
#include <queue>
// every element that is inserted in priority queue will contain a value an index i and an index j
class node
{
public:
    int element;
    int i;
    int j;

    node(int element, int row, int col)
    {
        this->element = element;
        this->i = row;
        this->j = col;
    }
};
class compare
{
public:
    bool operator()(node *a, node *b) // a is just inserted element and b is its child and this function will return true if child>parent that means there is no need to swap the elements
    {
        return a->element > b->element;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
    // we have got a input maxtrix that contains k arrays
    priority_queue<node *, vector<node *>, compare> minheap;
    // step 1:sare arrays ke first elements heap mein insert kro
    for (int i = 0; i < input.size(); i++)
    {
        node *temp = new node((*input[i])[0], i, 0);
        minheap.push(temp);
    }
    vector<int> ans; // to store final sorted array

    // step:2
    while (minheap.size() > 0)
    {
        node *temp = minheap.top();
        minheap.pop();
        int i = temp->i;
        int j = temp->j;
        ans.push_back(temp->element);
        if (j + 1 < (*input[i]).size())
        {
            node *temp = new node((*input[i])[j + 1], i, j + 1);
            minheap.push(temp);
        }
    }
    return ans;
}