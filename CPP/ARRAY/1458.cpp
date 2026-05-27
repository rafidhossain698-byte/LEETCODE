#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/* ======= SOLUTION (PASTE THIS PART IN LEETCODE) ======= */
class Solution
{
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {

        int n = nums1.size();
        int m = nums2.size();

        vector<vector<long long>> dp(n, vector<long long>(m, LLONG_MIN));

        dp[0][0] = (long long)nums1[0] * nums2[0];

        // first row
        for (int j = 1; j < m; j++)
        {
            dp[0][j] = max(dp[0][j - 1],
                           (long long)nums1[0] * nums2[j]);
        }

        // first col
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0],
                           (long long)nums1[i] * nums2[0]);
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {

                long long prod = (long long)nums1[i] * nums2[j];

                dp[i][j] = max({dp[i - 1][j],
                                dp[i][j - 1],
                                dp[i - 1][j - 1] + prod,
                                prod});
            }
        }

        return (int)dp[n - 1][m - 1];
    }
};
/* ====================================================== */

int main()
{

    Solution sol;

    vector<int> nums1 = {2, 1, -2, 5};
    vector<int> nums2 = {3, 0, -6};

    cout << sol.maxDotProduct(nums1, nums2) << endl;

    return 0;
}