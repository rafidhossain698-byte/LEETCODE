#include <iostream>

using namespace std;

/* ======= SOLUTION (PASTE THIS PART IN LEETCODE) ======= */
class Solution
{
public:
    int numOfWays(int n)
    {

        const long long MOD = 1000000007;

        long long aba = 6;
        long long abc = 6;

        for (int i = 2; i <= n; i++)
        {

            long long newAba = (aba * 3 + abc * 2) % MOD;
            long long newAbc = (aba * 2 + abc * 2) % MOD;

            aba = newAba;
            abc = newAbc;
        }

        return (aba + abc) % MOD;
    }
};
/* ====================================================== */

int main()
{

    Solution sol;

    int n = 3;

    cout << sol.numOfWays(n) << endl;

    return 0;
}