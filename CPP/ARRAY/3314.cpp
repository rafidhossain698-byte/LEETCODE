#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {

        vector<int> ans;

        for (int num : nums)
        {

            int best = -1;

            for (int x = 0; x <= num; x++)
            {

                if ((x | (x + 1)) == num)
                {
                    best = x;
                    break; // first valid is minimal
                }
            }

            ans.push_back(best);
        }

        return ans;
    }
};

int main()
{

    Solution sol;

    vector<int> nums = {2, 3, 5, 7};

    vector<int> ans = sol.minBitwiseArray(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}