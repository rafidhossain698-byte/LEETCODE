#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ps(m + 1, vector<int>(n + 1, 0));

        // build prefix sum
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                ps[i][j] = mat[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
            }
        }

        auto getSum = [&](int r, int c, int k)
        {
            return ps[r + k][c + k] - ps[r][c + k] - ps[r + k][c] + ps[r][c];
        };

        int best = 0;

        for (int k = 1; k <= min(m, n); k++)
        {

            for (int i = 0; i + k <= m; i++)
            {
                for (int j = 0; j + k <= n; j++)
                {

                    if (getSum(i, j, k) <= threshold)
                    {
                        best = max(best, k);
                    }
                }
            }
        }

        return best;
    }
};

int main()
{

    Solution sol;

    vector<vector<int>> mat = {
        {1, 1, 3, 2, 4, 3, 2},
        {1, 1, 3, 2, 4, 3, 2},
        {1, 1, 3, 2, 4, 3, 2}};

    int threshold = 4;

    cout << sol.maxSideLength(mat, threshold) << endl;

    return 0;
}
