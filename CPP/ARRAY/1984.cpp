#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int ans = INT_MAX;

        for (int i = 0; i + k - 1 < nums.size(); i++)
        {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {90};
    int k = 1;

    cout << sol.minimumDifference(nums, k) << endl;

    return 0;
}