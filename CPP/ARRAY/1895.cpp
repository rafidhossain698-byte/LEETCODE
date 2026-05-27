#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isMagic(vector<vector<int>> &grid, int r, int c, int k)
    {

        int target = 0;

        // first row sum
        for (int j = c; j < c + k; j++)
        {
            target += grid[r][j];
        }

        // check rows
        for (int i = r; i < r + k; i++)
        {

            int sum = 0;
            for (int j = c; j < c + k; j++)
            {
                sum += grid[i][j];
            }

            if (sum != target)
                return false;
        }

        // check columns
        for (int j = c; j < c + k; j++)
        {

            int sum = 0;
            for (int i = r; i < r + k; i++)
            {
                sum += grid[i][j];
            }

            if (sum != target)
                return false;
        }

        // main diagonal
        int d1 = 0;
        for (int i = 0; i < k; i++)
        {
            d1 += grid[r + i][c + i];
        }

        if (d1 != target)
            return false;

        // anti diagonal
        int d2 = 0;
        for (int i = 0; i < k; i++)
        {
            d2 += grid[r + i][c + k - 1 - i];
        }

        if (d2 != target)
            return false;

        return true;
    }

    int largestMagicSquare(vector<vector<int>> &grid)
    {

        int m = grid.size();
        int n = grid[0].size();

        for (int k = min(m, n); k >= 1; k--)
        {

            for (int i = 0; i + k <= m; i++)
            {
                for (int j = 0; j + k <= n; j++)
                {

                    if (isMagic(grid, i, j, k))
                        return k;
                }
            }
        }

        return 1;
    }
};

int main()
{

    Solution sol;

    vector<vector<int>> grid = {
        {7, 1, 4, 5, 6},
        {2, 5, 1, 6, 4},
        {1, 5, 4, 3, 2},
        {1, 2, 7, 3, 4}};

    cout << sol.largestMagicSquare(grid) << endl;

    return 0;
}