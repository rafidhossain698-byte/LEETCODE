#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {

        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for (int i = 0; i <= n; i++)
        {

            int h = (i == n ? 0 : heights[i]);

            while (!st.empty() && h < heights[st.top()])
            {

                int height = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : (i - st.top() - 1);

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {

        if (matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> height(cols, 0);
        int result = 0;

        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < cols; j++)
            {

                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            result = max(result, largestRectangleArea(height));
        }

        return result;
    }
};

int main()
{

    Solution sol;

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    cout << sol.maximalRectangle(matrix) << endl;

    return 0;
}