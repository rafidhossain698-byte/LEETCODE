#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    bool isSorted(vector<long long> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int> &nums)
    {

        vector<long long> a(nums.begin(), nums.end());
        int ops = 0;

        while (!isSorted(a))
        {

            long long bestSum = LLONG_MAX;
            int idx = -1;

            for (int i = 0; i < (int)a.size() - 1; i++)
            {

                long long sum = a[i] + a[i + 1];

                if (sum < bestSum)
                {
                    bestSum = sum;
                    idx = i;
                }
            }

            // merge at idx
            long long merged = a[idx] + a[idx + 1];

            a.erase(a.begin() + idx);
            a[idx] = merged;

            ops++;
        }

        return ops;
    }
};

int main()
{

    Solution sol;

    vector<int> nums = {5, 2, 3, 1};

    cout << sol.minimumPairRemoval(nums) << endl;

    return 0;
}
