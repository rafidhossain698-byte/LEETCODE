#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int getMaxGap(vector<int> &bars)
    {

        sort(bars.begin(), bars.end());

        int best = 1;
        int cnt = 1;

        for (int i = 1; i < (int)bars.size(); i++)
        {

            if (bars[i] == bars[i - 1] + 1)
            {
                cnt++;
            }
            else
            {
                best = max(best, cnt);
                cnt = 1;
            }
        }

        best = max(best, cnt);
        return best;
    }

    int maximizeSquareHoleArea(int n, int m,
                               vector<int> &hBars,
                               vector<int> &vBars)
    {

        int maxH = getMaxGap(hBars);
        int maxV = getMaxGap(vBars);

        int side = min(maxH, maxV) + 1;

        return side * side;
    }
};

int main()
{

    Solution sol;

    int n = 2, m = 3;

    vector<int> hBars = {2, 3};
    vector<int> vBars = {2, 4};

    cout << sol.maximizeSquareHoleArea(n, m, hBars, vBars) << endl;

    return 0;
}