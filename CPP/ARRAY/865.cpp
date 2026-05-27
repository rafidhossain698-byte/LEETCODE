#include <iostream>
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
    pair<int, TreeNode *> dfs(TreeNode *root)
    {
        if (!root)
            return {0, nullptr};

        auto L = dfs(root->left);
        auto R = dfs(root->right);

        if (L.first > R.first)
            return {L.first + 1, L.second};

        if (R.first > L.first)
            return {R.first + 1, R.second};

        return {L.first + 1, root};
    }

    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        return dfs(root).second;
    }
};

int main()
{

    Solution sol;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    TreeNode *ans = sol.subtreeWithAllDeepest(root);

    cout << ans->val << endl;

    return 0;
}