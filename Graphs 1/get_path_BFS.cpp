// O(V+E)
// O(V^2)
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;
vector<int> getPath_BFS(int **edges, int n, bool *visited, int sv, int ev)
{
    vector<int> v;
    queue<int> pending_vertices; // this queue will contain vertices we have seen but yet not printed
    unordered_map<int, int> ourmap;
    pending_vertices.push(sv);
    visited[sv] = true;
    while (!pending_vertices.empty())
    {

        int currentvertex = pending_vertices.front();
        pending_vertices.pop();
        if (currentvertex == ev) // path mil gya ajao vector mein insert krien
        {
            v.push_back(currentvertex);
            while (ourmap.count(currentvertex) > 0)
            {
                currentvertex = ourmap[currentvertex];
                v.push_back(currentvertex);
            }
            return v;
        }
        for (int i = 0; i < n; i++)
        {

            if (edges[currentvertex][i] == 1 && !visited[i])
            {
                ourmap[i] = currentvertex;
                visited[i] = true;
                pending_vertices.push(i);
            }
        }
    }
    return v;
}
int main()
{
    int sv, ev; // starting vertex and ending vertex
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s; // first vertex and second vertex
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    cin >> sv;
    cin >> ev;
    bool *visited = new bool[n]; // we have created visited array to keep track of vertices we have already printed
    for (int i = 0; i < n; i++)
    {
        visited[i] = false; // nothing is visited initially
    }
    vector<int> v = getPath_BFS(edges, n, visited, sv, ev);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    // delete memory
    for (int i = 0; i < n; i++) // adjancy matrix deleted
    {
        delete[] edges[i];
    }
    delete[] edges;

    delete[] visited; // visited array deleted

    return 0;
}
