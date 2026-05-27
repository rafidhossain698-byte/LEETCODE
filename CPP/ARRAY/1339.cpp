#include <iostream>
using namespace std;

/* ===== Tree Node Definition (needed for VS Code only) ===== */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* ======= SOLUTION (PASTE THIS PART IN LEETCODE) ======= */
class Solution
{
public:
    long long totalSum = 0;
    long long maxProd = 0;

    long long dfsSum(TreeNode *node)
    {
        if (!node)
            return 0;
        return node->val + dfsSum(node->left) + dfsSum(node->right);
    }

    long long dfs(TreeNode *node)
    {

        if (!node)
            return 0;

        long long sum = node->val + dfs(node->left) + dfs(node->right);

        maxProd = max(maxProd, sum * (totalSum - sum));

        return sum;
    }

    int maxProduct(TreeNode *root)
    {

        totalSum = dfsSum(root);
        dfs(root);

        return maxProd % 1000000007;
    }
};
/* ====================================================== */

int main()
{

    /*
        Example:
              1
             / \
            2   3
           / \
          4   5
    */

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;

    cout << sol.maxProduct(root) << endl;

    return 0;
}