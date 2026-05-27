#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool bfs(int row, int col, vector<vector<int>> &cells, int day)
    {

        vector<vector<int>> grid(row, vector<int>(col, 0));

        for (int i = 0; i < day; i++)
        {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        queue<pair<int, int>> q;
        vector<vector<int>> vis(row, vector<int>(col, 0));

        for (int j = 0; j < col; j++)
        {
            if (grid[0][j] == 0)
            {
                q.push({0, j});
                vis[0][j] = 1;
            }
        }

        while (!q.empty())
        {

            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x == row - 1)
                return true;

            for (int k = 0; k < 4; k++)
            {

                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && ny >= 0 &&
                    nx < row && ny < col &&
                    !vis[nx][ny] &&
                    grid[nx][ny] == 0)
                {

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {

        int left = 1, right = cells.size();
        int ans = 0;

        while (left <= right)
        {

            int mid = left + (right - left) / 2;

            if (bfs(row, col, cells, mid))
            {
                ans = mid;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{

    Solution sol;

    int row = 2, col = 2;
    vector<vector<int>> cells = {{1, 1}, {2, 1}, {1, 2}, {2, 2}};

    cout << sol.latestDayToCross(row, col, cells) << endl;

    return 0;
}