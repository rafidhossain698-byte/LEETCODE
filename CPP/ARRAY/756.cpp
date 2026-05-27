#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int T[7][7];
    unordered_set<long long> seen;

    bool solve(vector<vector<int>> &A, long long R, int N, int i)
    {

        if (N == 1 && i == 1)
            return true;

        if (i == N)
        {
            if (seen.count(R))
                return false;
            seen.insert(R);
            return solve(A, 0, N - 1, 0);
        }

        int w = T[A[N][i]][A[N][i + 1]];

        for (int b = 0; b < 7; b++)
        {
            if (w & (1 << b))
            {
                A[N - 1][i] = b;

                if (solve(A, R * 8 + (b + 1), N, i + 1))
                    return true;
            }
        }

        return false;
    }

    bool pyramidTransition(string bottom, vector<string> &allowed)
    {

        memset(T, 0, sizeof(T));

        for (auto &a : allowed)
        {
            int x = a[0] - 'A';
            int y = a[1] - 'A';
            int z = a[2] - 'A';
            T[x][y] |= (1 << z);
        }

        int N = bottom.size();
        vector<vector<int>> A(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++)
        {
            A[N - 1][i] = bottom[i] - 'A';
        }

        return solve(A, 0, N - 1, 0);
    }
};
/* ====================================================== */

int main()
{
    Solution sol;

    string bottom = "ABC";
    vector<string> allowed = {"ABD", "BCE", "DEF", "FFF"};

    cout << sol.pyramidTransition(bottom, allowed) << endl;

    return 0;
}