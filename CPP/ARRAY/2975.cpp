#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int maximizeSquareArea(int m, int n,
                           vector<int> &hFences,
                           vector<int> &vFences)
    {

        const long long MOD = 1e9 + 7;

        vector<int> h = hFences, v = vFences;

        h.push_back(1);
        h.push_back(m);

        v.push_back(1);
        v.push_back(n);

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        unordered_set<long long> hs, vs;

        int hsz = h.size();
        int vsz = v.size();

        // all horizontal gaps
        for (int i = 0; i < hsz; i++)
        {
            for (int j = i + 1; j < hsz; j++)
            {
                hs.insert(h[j] - h[i]);
            }
        }

        // all vertical gaps
        for (int i = 0; i < vsz; i++)
        {
            for (int j = i + 1; j < vsz; j++)
            {
                vs.insert(v[j] - v[i]);
            }
        }

        long long best = 0;

        for (auto x : hs)
        {
            if (vs.count(x))
            {
                best = max(best, x);
            }
        }

        if (best == 0)
            return -1;

        return (best * best) % MOD;
    }
};

int main()
{

    Solution sol;

    int m = 6, n = 7;
    vector<int> hFences = {2};
    vector<int> vFences = {4};

    cout << sol.maximizeSquareArea(m, n, hFences, vFences) << endl;

    return 0;
}