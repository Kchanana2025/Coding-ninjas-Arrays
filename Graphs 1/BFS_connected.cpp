// O(V+E)
// O(V^2)
#include <iostream>
#include <queue>
using namespace std;
// agar ek node ke just neeche wale level pe 4 nodes hain toh bfs execute krte smay wo apha betically print hongi
// agar 8 vertices input karoge toh vertices ki values 0 se 7 tak daalna
void print(int **edges, int n, int sv, bool *visited) // the third parameter is the starting vertex jahan se traversal shuru krna hai
{
    queue<int> pending_vertices; // this queue will contain vertices we have seen but yet not printed

    pending_vertices.push(sv);
    visited[sv] = true; // same as BFS

    while (!pending_vertices.empty())
    {
        int currentvertex = pending_vertices.front(); // current vertex ko print kro aur uske adjancent vertices  ko queue mein faal do
        cout << currentvertex << " ";
        pending_vertices.pop();
        for (int i = 0; i < n; i++)
        {
            // if (i == currentvertex)//no need
            // {
            //     continue;
            // }
            if (edges[currentvertex][i] == 1)
            {
                if (visited[i]) // if that vertex is visited then continue
                {
                    continue;
                }
                visited[i] = true;
                pending_vertices.push(i);
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
    cout << "BFS" << endl;
    print(edges, n, 0, visited); // print graph
    // agar hm staring vertex na bhjte which is 0 here tab bhi hum function mein jaake 0 se start krke question ko kr skte thee

    // delete memory
    for (int i = 0; i < n; i++) // adjancy matrix deleted
    {
        delete[] edges[i];
    }
    delete[] edges;

    delete[] visited; // visited array deleted

    return 0;
}