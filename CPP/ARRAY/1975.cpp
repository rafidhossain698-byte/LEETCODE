#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {

        long long sum = 0;
        long long minAbs = LLONG_MAX;
        int negCount = 0;

        for (auto &row : matrix)
        {
            for (int x : row)
            {

                long long val = llabs(x);

                sum += val;
                minAbs = min(minAbs, val);

                if (x < 0)
                    negCount++;
            }
        }

        if (negCount % 2 == 1)
        {
            sum -= 2 * minAbs;
        }

        return sum;
    }
};

int main()
{

    Solution sol;

    vector<vector<int>> matrix = {
        {1, -1},
        {-1, 1}};

    cout << sol.maxMatrixSum(matrix) << endl;

    return 0;
}