// O(V+E)(hr ek vertex aur uske edges ke hi baar traverse hote hain.Na vertex repeat hota hai na edges repeat hote hain.isliye complexity is O(V+E)
// O(V^2) adjancy matrix
#include <iostream>
#include <vector>
using namespace std;
void DFS_traversal(int **edges, int n, bool *visited, int sv) // ev stands for end vertex
{
    visited[sv] = true;
    for (int i = 0; i < n; i++) // jitne bhi adjacent vertices honge sv(starting vertex) ke sabhi ko visited krte hai
    {
        if (edges[sv][i] == 1 && !visited[i])
        {
            DFS_traversal(edges, n, visited, i);
        }
    }
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
    DFS_traversal(edges, n, visited, sv);
    if (visited[ev])
        cout << "true";
    else
        cout << "false";

    // delete memory
    for (int i = 0; i < n; i++) // adjancy matrix deleted
    {
        delete[] edges[i];
    }
    delete[] edges;

    delete[] visited; // visited array deleted

    return 0;
}
