// O(V+E)
// O(V^2)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void DFS_traversal(int **edges, int n, bool *visited, int sv, vector<vector<int>> &output, vector<int> &ans)
{
    visited[sv] = true;
    ans.push_back(sv);
    for (int i = 0; i < n; i++) // sv ke adjancent sabhi vertices pe dfs lgao
    {
        if (edges[sv][i] == 1 && !visited[i])
        {

            DFS_traversal(edges, n, visited, i, output, ans);
        }
    }
}
void DFS_traversal_helper(int **edges, int n, bool *visited, vector<vector<int>> &output)
{
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> ans;
            DFS_traversal(edges, n, visited, i, output, ans);
            sort(ans.begin(), ans.end());
            output.push_back(ans);
        }
    }
}
int main()
{

    int n;
    int e;
    cin >> n;
    cin >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int sv, ev;
        cin >> sv;
        cin >> ev;
        edges[sv][ev] = 1;
        edges[ev][sv] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    vector<vector<int>> output;
    DFS_traversal_helper(edges, n, visited, output);
    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {

            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
}