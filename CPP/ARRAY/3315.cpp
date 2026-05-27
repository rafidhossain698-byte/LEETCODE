#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long compute(long long num)
    {

        long long best = -1;

        for (int i = 0; i < 31; i++)
        {

            long long x = 0;

            bool ok = true;

            for (int b = 30; b >= 0; b--)
            {

                if (b > i)
                {
                    // must match num
                    if (num & (1LL << b))
                    {
                        x |= (1LL << b);
                    }
                }
                else if (b == i)
                {
                    // forced 0
                }
                else
                {
                    // all 1s below
                    x |= (1LL << b);
                }
            }

            if ((x | (x + 1)) == num)
            {
                if (best == -1 || x < best)
                    best = x;
            }
        }

        return best;
    }

    vector<int> minBitwiseArray(vector<int> &nums)
    {

        vector<int> ans;

        for (long long num : nums)
        {
            ans.push_back((int)compute(num));
        }

        return ans;
    }
};

int main()
{

    Solution sol;

    vector<int> nums = {11, 13, 31};

    vector<int> ans = sol.minBitwiseArray(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
