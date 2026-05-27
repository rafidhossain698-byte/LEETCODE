#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* ======= SOLUTION (PASTE THIS PART IN LEETCODE) ======= */
class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // DP: longest common subsequence ASCII sum
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + (int)s1[i - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        int sum1 = 0, sum2 = 0;

        for (char c : s1)
            sum1 += (int)c;
        for (char c : s2)
            sum2 += (int)c;

        return (sum1 + sum2) - 2 * dp[n][m];
    }
};
/* ====================================================== */

int main()
{

    Solution sol;

    string s1 = "sea";
    string s2 = "eat";

    cout << sol.minimumDeleteSum(s1, s2) << endl;

    return 0;
}