#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    double calc(vector<vector<int>> &squares, double h)
    {

        double area = 0;

        for (auto &s : squares)
        {

            double y = s[1];
            double l = s[2];

            double top = y + l;

            if (h <= y)
            {
                area += l * l;
            }
            else if (h < top)
            {
                area += (top - h) * l;
            }
        }

        return area;
    }

    double separateSquares(vector<vector<int>> &squares)
    {

        double low = 0, high = 0;

        for (auto &s : squares)
        {
            high = max(high, (double)s[1] + s[2]);
        }

        double total = 0;
        for (auto &s : squares)
        {
            total += (double)s[2] * s[2];
        }

        double target = total / 2.0;

        for (int i = 0; i < 80; i++)
        {

            double mid = (low + high) / 2.0;

            if (calc(squares, mid) > target)
                low = mid;
            else
                high = mid;
        }

        return high;
    }
};

int main()
{

    Solution sol;

    vector<vector<int>> squares = {
        {0, 0, 1},
        {2, 2, 1}};

    cout << sol.separateSquares(squares) << endl;

    return 0;
}