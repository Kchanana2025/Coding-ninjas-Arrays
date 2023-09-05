// O(V+E)
// O(V^2)
#include <queue>
#include <iostream>
using namespace std;
void print(int **edges, int n, int sv, bool *visited) // the third parameter is the starting vertex jahan se traversal shuru krna hai
{
    queue<int> pending_vertices;
    // pending_vertices stores wo vertices jo visit ho chuke hain pr na hi print hue hain aur na hi inke adjancent vertices queue mein gye hain
    visited[sv] = true; // same as BFS
    pending_vertices.push(sv);

    while (pending_vertices.size() != 0)
    {
        int currentvertex = pending_vertices.front(); // cuurent vertex ko print kro aur uske adjancent vertices  ko queue mein faal do
        cout << currentvertex << " ";
        pending_vertices.pop();
        for (int i = 0; i < n; i++)
        {

            if (edges[currentvertex][i] == 1)
            {
                if (visited[i]) // if that vertex is visited then continue
                {
                    continue;
                }
                visited[i] = true;        // if not visited then then mark it as true
                pending_vertices.push(i); // and then push it in queue
            }
        }
    }
}
void print_helper(int **edges, int n) // the third parameter is the starting vertex jahan se traversal shuru krna hai
{
    bool *visited = new bool[n]; // we have created visited array to keep track of vertices we have already printed
    for (int i = 0; i < n; i++)
    {
        visited[i] = false; // nothing is visited initially
    }
    for (int sv = 0; sv < n; sv++)
    {
        if (!visited[sv]) // jo vertex visited nai hai uske upar bhi BFS chalao
        {
            print(edges, n, sv, visited);
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

    print_helper(edges, n); // print graph

    // delete memory
    for (int i = 0; i < n; i++) // adjancy matrix deleted
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}