#include <iostream>
using namespace std;
void print(int **edges, int n, int sv, bool *visited) // the third parameter is the starting vertex jahan se traversal shuru krna hai
{
    cout << sv << endl;
    visited[sv] = true; // graph ke vertices ko array ke indexes man rhe hai.i.e agar 3 rd vertex ki baat ho rhi hai toh 3rd index store krega ki wo visited hai ya nai
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
            print(edges, n, i, visited);
        }
    }
}
int main()
{
    int n; // no of vertices
    int e; // no of edges
    cin >> n >> e;
    // we are declaring adjancy matrix to store weather a particular edge is present or not in  graph(represented by 0 or 1)(hm boolean adjancy matrix bhi bna skte thee that stores T or F)
    int **edges = new int *[n]; // this is array to store pointers of arrays
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            // garbage values hta rhe hai matrix ki
            edges[i][j] = 0; // initially koi edges  present nai hai
        }
    }
    // taking input of edges and filling adjancy matrix
    for (int i = 0; i < e; i++)
    {
        int f, s; // first vertex and second vertex
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n]; // we have created visited array to keep track of vertices we have already printed
    for (int i = 0; i < n; i++)
    {
        visited[i] = false; // nothing is visited initially
    }
    print(edges, n, 0, visited); // print graph
    // array as pointer and matrix as double pointer jata hai(jab dyanmic hote hai array aur matrix) toh hmien uska size sath  bhjna padhta hai
    // array as pointer and matrix as pointer jata hai(jab static hote hai array aur matrix) toh hmien uska size sath  bhjna padhta hai

    // delete memory
    for (int i = 0; i < n; i++) // adjancy matrix deleted
    {
        delete edges[i];
    }

    delete visited; // visited array deleted

    return 0;
}