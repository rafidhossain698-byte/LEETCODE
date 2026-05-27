#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;
        int ans = 0;

        while (i < j)
        {
            ans = max(ans, nums[i] + nums[j]);
            i++;
            j--;
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {3, 5, 2, 3};

    cout << sol.minPairSum(nums) << endl;

    return 0;
}