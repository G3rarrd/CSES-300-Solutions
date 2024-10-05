#include <bits/stdc++.h>

using namespace std;

class GridPaths
{
public:
    int **memo;
    int direction[2][2] = {{0, 1}, {1, 0}};
    int MOD = 1e9+7;
    GridPaths(int n)
    {
        // Allocate memory for `n` rows
        memo = new int *[n];

        for (int i = 0; i < n; ++i)
        {
            memo[i] = new int[n];
            memset(memo[i], -1, n * sizeof(int));
        }

        memo[n - 1][n - 1] = 1;
    }

    ~GridPaths()
    {
        for (int i = 0; i < sizeof(memo) / sizeof(memo[0]); i++)
        {
            delete[] memo[i];
        }

        delete[] memo;
    }

    int solve(int row, int col, int n, string grid[])
    {
        if (grid[row][col] == '*') {
            return 0;
        }

        if (memo[row][col] > -1)
        {
            return memo[row][col];
        }

        memo[row][col] = 0;

        for (int i = 0; i < 2; i++)
        {
            int dx = direction[i][0];
            int dy = direction[i][1];

            int newRow = row + dx;
            int newCol = col + dy;

            if (newRow < n && newCol < n && grid[newRow][newCol] != '*')
            {
                // cout << val << ' ' << newRow << ' ' << newCol << endl;
                memo[row][col] += solve(newRow, newCol, n, grid) ;
                memo[row][col] %= MOD;
            }
        }

        return memo[row][col];
    }
};
int main()
{
    int n;
    cin >> n;
    string grid[n];

    for (int i = 0; i < n; i++)
    {
       cin >> grid[i] ;
    }

    GridPaths GP(n);
    cout << GP.solve(0, 0, n, grid);

    return 0;
}