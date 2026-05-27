#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    long long largestSquareArea(vector<vector<int>> &bottomLeft,
                                vector<vector<int>> &topRight)
    {

        int n = bottomLeft.size();
        long long best = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                long long x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long y1 = max(bottomLeft[i][1], bottomLeft[j][1]);

                long long x2 = min(topRight[i][0], topRight[j][0]);
                long long y2 = min(topRight[i][1], topRight[j][1]);

                if (x1 < x2 && y1 < y2)
                {

                    long long width = x2 - x1;
                    long long height = y2 - y1;

                    long long side = min(width, height);
                    best = max(best, side * side);
                }
            }
        }

        return best;
    }
};

int main()
{

    Solution sol;

    vector<vector<int>> bottomLeft = {
        {1, 1},
        {2, 2},
        {3, 1}};

    vector<vector<int>> topRight = {
        {3, 3},
        {4, 4},
        {6, 6}};

    cout << sol.largestSquareArea(bottomLeft, topRight) << endl;

    return 0;
}