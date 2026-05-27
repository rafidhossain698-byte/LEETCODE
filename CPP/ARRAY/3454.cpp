#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    struct Event
    {
        long long y;
        int x1, x2;
        int type;
    };

    vector<long long> xs;
    vector<long long> seg;
    vector<long long> cover;

    void update(int node, int l, int r, int ql, int qr, int val)
    {

        if (qr < l || r < ql)
            return;

        if (ql <= l && r <= qr)
        {
            cover[node] += val;
        }
        else
        {
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val);
            update(node * 2 + 1, mid + 1, r, ql, qr, val);
        }

        if (cover[node] > 0)
        {
            seg[node] = xs[r + 1] - xs[l];
        }
        else if (l == r)
        {
            seg[node] = 0;
        }
        else
        {
            seg[node] = seg[node * 2] + seg[node * 2 + 1];
        }
    }

    double separateSquares(vector<vector<int>> &squares)
    {

        vector<Event> events;
        xs.clear();

        for (auto &s : squares)
        {

            int x = s[0], y = s[1], l = s[2];

            xs.push_back(x);
            xs.push_back(x + l);

            events.push_back({(long long)y, x, x + l, 1});
            events.push_back({(long long)y + l, x, x + l, -1});
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        sort(events.begin(), events.end(),
             [](auto &a, auto &b)
             { return a.y < b.y; });

        int n = xs.size();

        seg.assign(4 * n, 0);
        cover.assign(4 * n, 0);

        auto getIdx = [&](int x)
        {
            return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
        };

        double total = 0;
        long long prevY = events[0].y;

        for (auto &e : events)
        {

            long long curY = e.y;

            double width = seg[1];
            total += width * (curY - prevY);

            int l = getIdx(e.x1);
            int r = getIdx(e.x2) - 1;

            update(1, 0, n - 2, l, r, e.type);

            prevY = curY;
        }

        double half = total / 2.0;

        // second sweep
        fill(seg.begin(), seg.end(), 0);
        fill(cover.begin(), cover.end(), 0);

        prevY = events[0].y;
        double curArea = 0;

        for (auto &e : events)
        {

            long long curY = e.y;

            double width = seg[1];
            double nextArea = curArea + width * (curY - prevY);

            if (nextArea >= half)
            {
                double need = half - curArea;
                return prevY + need / width;
            }

            curArea = nextArea;

            int l = getIdx(e.x1);
            int r = getIdx(e.x2) - 1;

            update(1, 0, n - 2, l, r, e.type);

            prevY = curY;
        }

        return -1;
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