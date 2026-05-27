#include <iostream>
#include <vector>

using namespace std;

/* ======= SOLUTION (PASTE THIS PART IN LEETCODE) ======= */
class Solution
{
public:
    int sumFourDivisors(int n)
    {

        int cnt = 0;
        int sum = 0;

        for (int i = 1; i * i <= n; i++)
        {

            if (n % i == 0)
            {

                if (i * i == n)
                {
                    cnt++;
                    sum += i;
                }
                else
                {
                    cnt += 2;
                    sum += i + (n / i);
                }
            }

            if (cnt > 4)
                return 0;
        }

        return (cnt == 4) ? sum : 0;
    }

    int sumFourDivisors(vector<int> &nums)
    {

        int ans = 0;

        for (int x : nums)
        {
            ans += sumFourDivisors(x);
        }

        return ans;
    }
};
/* ====================================================== */

int main()
{

    Solution sol;

    vector<int> nums = {21, 4, 7};

    cout << sol.sumFourDivisors(nums) << endl;

    return 0;
}