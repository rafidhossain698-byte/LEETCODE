#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {

        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;

        for (int i = 1; i < arr.size(); i++)
        {
            minDiff = min(minDiff, arr[i] - arr[i - 1]);
        }

        vector<vector<int>> res;

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i - 1] == minDiff)
            {
                res.push_back({arr[i - 1], arr[i]});
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;

    vector<int> arr = {4, 2, 1, 3};

    vector<vector<int>> ans = sol.minimumAbsDifference(arr);

    for (auto &p : ans)
    {
        cout << "[" << p[0] << "," << p[1] << "] ";
    }
}