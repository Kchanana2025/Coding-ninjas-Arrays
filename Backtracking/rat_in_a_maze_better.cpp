// time ka utna nai socha jata bracktracking ke sawalo mein kyunki kyunki sari paths toh dekhne hi hain
#include <bits/stdc++.h>
using namespace std;
if (x < 0 || x >= n || y < 0 || y >= n || maze[x][y] == 0 || solution[x][y] == 1)
    return;
void ratInamaze_help(int maze[][20], int **solution, int x, int y, int n)
{

    if (x == n - 1 && y == n - 1) // last cell reached  print the matrix
    {
        solution[x][y] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << solution[i][j] << " ";
            }
        }
        cout << endl;
        solution[x][y] = 0; // isko isliye lgaya kyunki upar add jayega 2nd solution ke waqt
        return;
    }

    solution[x][y] = 1;
    ratInamaze_help(maze, solution, x + 1, y, n);
    ratInamaze_help(maze, solution, x - 1, y, n);
    ratInamaze_help(maze, solution, x, y + 1, n);
    ratInamaze_help(maze, solution, x, y - 1, n);
    solution[x][y] = 0;
    return;
}

void ratInamaze(int maze[][20], int n)
{
    // creating a dyanmic array of pointers to hold address of several arrays
    int **solution = new int *[n];

    // creating n arrays of size n i.e n*n matrix
    for (int i = 0; i < n; i++)
    {
        solution[i] = new int[n];
        for (int j = 0; j < n; j++)
            solution[i][j] = 0;
    }

    ratInamaze_help(maze, solution, 0, 0, n);
    // maze is given matrix
    // solution is final matrix
    // 0 is row index where you wish to place
    // 0 is col index where you wish to place
}
int main()
{
    int n;
    cin >> n;
    int maze[20][20] = {0}; // as n=at max 18
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }

    ratInamaze(maze, n);
}