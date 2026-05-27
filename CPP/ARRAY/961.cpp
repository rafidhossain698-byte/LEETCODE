#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {

        unordered_set<int> st;

        for (int num : nums)
        {

            if (st.count(num))
                return num;

            st.insert(num);
        }

        return -1;
    }
};

int main()
{

    Solution sol;

    vector<int> nums = {1, 2, 3, 3};

    cout << sol.repeatedNTimes(nums) << endl;

    return 0;
}