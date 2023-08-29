// isme ans global nai bnaya bss
//  recursive function mein ya toh base case ko if mein daalke return krdo ya phir base case ko if mein daaldo aur baaki ke code ko else mein
#include <iostream>
#include <cstring>
using namespace std;
int board[11][11];
// vector<vector<int>> ans;//just because ans finally return krna hai toh hr function apna kaam krke vector return kre uss se behtar vector ko global bna do aur usme updates krte raho
// nai bhai doing itni imp things global is not a good practice
bool isPossible(int n, int row, int col)
{
    // row collision toh phle hi sort out kr lia hai hmne

    // lets check  column collision
    for (int i = row - 1; i >= 0; i--) // abhi tak ki jitni bhi queens daali hai check krlo ki koi bhi colindex=col pe toh nai hai?(row index se neeche nai dekha because udhar wali rows mein queens daali hi nai hui toh udhar kyu dekhoge bhai)
    {
        if (board[i][col] == 1)
            return false;
    }
    // lets check upper left diagnol
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
    // lets check upper right diagnol
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}
vector<vector<int>> n_Queens_helper(int n, int row, vector<vector<int>> &ans)
{
    // base case
    vector<int> ans_1;
    if (row == n) // means that we have found a solution and we will print it
    {
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {

                ans_1.push_back(board[i][j]);
            }
        }
        ans.push_back(ans_1);
        //   cout<<ans.size();
        return ans;
    }
    // small calculation
    for (int j = 0; j < n; j++) // we will just care about all columns for rowindex=0(row=1 to row=n-1 will be handled by recursion)
    {

        if (isPossible(n, row, j))
        {
            board[row][j] = 1;
            ans = n_Queens_helper(n, row + 1, ans); // recursive call
            board[row][j] = 0;                      // cantrol 2 cases mein yaha pahuch skta h
            // case 1: ki board ki sari values sahi se mil gayi hain aur print hoke return ho gya hai aur ab naye solution dhundhege loop aage chala ke
            // case 2: ki hmari orginal placement of Queen Q1(kisi aage ki function call ke lie koi aage ki queen) hi galat thi toh hmnien function return kia aur uss value ko zero krke loop aaage chalaya.(koi aur soln dekhne ke lie)
        }
    }
    return ans;
}

vector<vector<int>> nQueens(int n)
{
    memset(board, 0, 11 * 11 * sizeof(int)); // to set all values of matrix as zero
    vector<vector<int>> ans;
    ans = n_Queens_helper(n, 0, ans); // we will send 2 parameters no of rows and row no
    // cout<<ans.size();
    return ans;
}