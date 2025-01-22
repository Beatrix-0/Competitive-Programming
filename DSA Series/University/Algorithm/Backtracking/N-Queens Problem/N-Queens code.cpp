#include <bits/stdc++.h>
using namespace std;

void addSolution(vector<vector<string>>& ans, vector<vector<char>>& board, int n)
{
    vector<string> tmp(n);
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            tmp[row] += board[row][col];
        }
    }
    ans.push_back(tmp);
}

bool isSafe(int row, int col, vector<vector<char>>& board, int n)
{
    // Check left horizontal line
    int x = row, y = col;
    while (y >= 0)
    {
        if (board[x][y] == 'Q')
        {
            return false;
        }
        y--;
    }

    // Check upward left diagonal
    x = row;
    y = col;
    while (y >= 0 && x >= 0)
    {
        if (board[x][y] == 'Q')
        {
            return false;
        }
        x--;
        y--;
    }

    // Check downward left diagonal
    x = row;
    y = col;
    while (y >= 0 && x < n)    // Correct traversal
    {
        if (board[x][y] == 'Q')
        {
            return false;
        }
        x++;
        y--;
    }

    return true;
}

void solve(int col, vector<vector<string>>& ans, vector<vector<char>>& board, int n)
{
    // Base case
    if (col == n)
    {
        addSolution(ans, board, n);
        return;
    }
    // Traverse rows for the current column
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            board[row][col] = 'Q';
            solve(col + 1, ans, board, n);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<char>> chessboard(n, vector<char>(n, '.'));
    vector<vector<string>> ans;
    solve(0, ans, chessboard, n);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<string>> ans = solveNQueens(n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << '\n';
        }
        cout << '\n';
    }

    return 0;
}

// Resources : https://favtutor.com/blogs/backtracking-algorithm-problems-cpp
// Video : https://youtu.be/i05Ju7AftcM?si=v3hm4sRqCFXlIVVU
