#include <iostream>
using namespace std;
void print(int **edges, int n, int sv, bool *visited, queue<int> pending_nodes) // the third parameter is the starting vertex jahan se traversal shuru krna hai
{
    if (visited[sv] == false)
    {
        visited[sv] = true; // same as BFS
        pending_nodes.push(sv);
    }
    while (pending_nodes.size != 0)
    {
        sv = pending_nodes.top(); // we are setting it sv so that jo bhi vertex queue se bahar nikle aur children ho toh neeche jaake wo children bhi add ho jaen
        cout << sv;
        pending_nodes.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == sv)
            {
                continue;
            }
            if (edges[sv][i] == 1)
            {
                if (visited[i]) // if that vertex is visited then continue
                {
                    continue;
                }
                visited[i] = true;
                pending_nodes.push(i);
            }
        }
    }
}
int main()
{
    int n; // no of vertices
    int e; // no of edges
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
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n]; // we have created visited array to keep track of vertices we have already printed
    for (int i = 0; i < n; i++)
    {
        visited[i] = false; // nothing is visited initially
    }
    queue<int> pending_nodes;
    print(edges, n, 0, visited, pending_nodes); // print graph

    // delete memory
    for (int i = 0; i < n; i++) // adjancy matrix deleted
    {
        delete edges[i];
    }

    delete visited; // visited array deleted

    return 0;
}