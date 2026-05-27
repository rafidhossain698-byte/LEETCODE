#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {

        queue<TreeNode *> q;
        q.push(root);

        int level = 1;
        int bestLevel = 1;
        long long maxSum = LLONG_MIN;

        while (!q.empty())
        {

            int size = q.size();
            long long sum = 0;

            for (int i = 0; i < size; i++)
            {

                TreeNode *node = q.front();
                q.pop();

                sum += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (sum > maxSum)
            {
                maxSum = sum;
                bestLevel = level;
            }

            level++;
        }

        return bestLevel;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    Solution sol;

    cout << sol.maxLevelSum(root) << endl;

    return 0;
}