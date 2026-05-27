#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <set>
#include <climits>

using namespace std;

class Solution
{
public:
    bool isMagic(vector<vector<int>> &grid, int r, int c)
    {

        vector<int> freq(10, 0);

        // Check numbers are 1 to 9 and distinct
        for (int i = r; i < r + 3; i++)
        {
            for (int j = c; j < c + 3; j++)
            {

                int val = grid[i][j];

                if (val < 1 || val > 9 || freq[val])
                    return false;

                freq[val] = 1;
            }
        }

        int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        // Rows
        for (int i = r; i < r + 3; i++)
        {
            if (grid[i][c] + grid[i][c + 1] + grid[i][c + 2] != sum)
                return false;
        }

        // Columns
        for (int j = c; j < c + 3; j++)
        {
            if (grid[r][j] + grid[r + 1][j] + grid[r + 2][j] != sum)
                return false;
        }

        // Diagonals
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum)
            return false;

        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>> &grid)
    {

        int rows = grid.size();
        int cols = grid[0].size();

        int count = 0;

        for (int i = 0; i <= rows - 3; i++)
        {
            for (int j = 0; j <= cols - 3; j++)
            {

                if (isMagic(grid, i, j))
                    count++;
            }
        }

        return count;
    }
};

int main()

{

    Solution sol;

    vector<vector<int>> grid = {

        {4, 3, 8, 4},

        {9, 5, 1, 9},

        {2, 7, 6, 2}

    };

    cout << sol.numMagicSquaresInside(grid) << endl;

    return 0;
}