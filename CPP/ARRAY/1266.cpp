#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {

        int time = 0;

        for (int i = 1; i < (int)points.size(); i++)
        {

            int dx = abs(points[i][0] - points[i - 1][0]);
            int dy = abs(points[i][1] - points[i - 1][1]);

            time += max(dx, dy);
        }

        return time;
    }
};

int main()
{

    Solution sol;

    vector<vector<int>> points = {
        {1, 1},
        {3, 4},
        {-1, 0}};

    cout << sol.minTimeToVisitAllPoints(points) << endl;

    return 0;
}