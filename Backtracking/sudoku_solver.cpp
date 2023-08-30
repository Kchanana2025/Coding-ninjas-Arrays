#include <bits/stdc++.h>
using namespace std;
#define N 9                                        // because grid is of 9*9 size
bool isSafeInRow(int grid[N][N], int row, int num) // weather that no is present in that row or not
{
    for (int j = 0; j < N; j++) // uss row ke sabhi columns check kr lie
    {
        if (num == grid[row][j])
        {
            return false;
        }
    }
    return true;
}
bool isSafeIncolumn(int grid[N][N], int col, int num) // weather that no is present in column or not
{
    for (int i = 0; i < N; i++) // us column ki sabhi rows check kr li
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }
    return true;
}
bool isSafeInBox(int grid[N][N], int row, int col, int num) // weather that no is present in that 3*3 box  or not
{

    // i ,j ko 0 se nai chla skte hamien unme rowfactor aur column factor daalne padhege
    int rowFactor = row - (row % 3);
    int colFactor = col - (col % 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; i < 3; j++)
        {
            if (grid[i + rowFactor][j + colFactor] == num)
                return false;
        }
    }
    return true;
}
bool isSafe(int grid[N][N], int row, int col, int num)
{
    if (isSafeInRow(grid, row, num) && isSafeIncolumn(grid, col, num) && isSafeInBox(grid, row, col, num))
    {
        return true;
    }
    return false;
}

bool findEmptyLocation(int grid[][N], int row, int col) // you can accept 2D matrix like grid[][N]or grid[N][N] not like this grid[][]
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0) // empty space is found
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false; // yaha cantrol tabhi ayega jab if mein cantrol ek baar bhi nai gaya ho i.e ek baar bhi usse grid[i][j]==0 na mila ho ,i.e no empty space i.e return false
}
// Note: agar koi piece of code ka hone ya na hone se hmare aage ka code bdl jat hai toh usse if bnane ki jagah bool function mein daal dia kro(code zyada dhang se smjh aa pata hai) jaise yaha find empty location ke lie kia h hmne ek if else statement lgane ke bjaye
bool solveSudoku(int grid[][N])
{
    // lets find an empty location
    int row, col;
    if (!findEmptyLocation(grid, row, col))
    {
        return true; // if no empty space is found that means the sudoku is comptely filled that means we must return true
    }
    // after this function call, row and col will contain indexes of empty space in grid
    // now lets place values in that empty space

    for (int i = 1; i < N; i++)
    {
        if (isSafe(grid, row, col, i))
        {
            grid[row][col] = i;
            if (solveSudoku(grid))
            {
                return true;
            }
            grid[row][col] = 0; // yaha cantrol tabhi ayega jab eg apne i=1 dala aur aage ka sudoku usse solve nai ho rha mtlb solve sudoku false return kr rha tab uss position pe zero assign ho jayega aur new value waha rakhne ke lie dobara se loop chalega
        }
    }
    return false; // agar 1 to 9 mein kuch bhi nai rakh paa rhe that means sudoku is invalid
}

int main()
{
    int grid[N][N];
    // we will input  the sudoku
    for (int i = 0; i < N; i++)
    {
        string s; // length of the input string would be 9
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            grid[i][j] = s[j] - '0'; // if s[j]=0 ,grid will store value as zero
        }
    }
    // we will send sudoku to solveSudoku
    if (solveSudoku(grid))
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        cout << "INVALID SUDOKU";
    }

    return 0;
}