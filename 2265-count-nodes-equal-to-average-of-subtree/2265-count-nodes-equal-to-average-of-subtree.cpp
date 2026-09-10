/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int ans;

public:
    Solution() { this->ans = 0; }
    int averageOfSubtree(TreeNode* root) {
        auto p = solve(root);
        return ans;
    }

private:
    pair<int, int> solve(TreeNode* root) {
        if (!root)
            return {0, 0};
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;
        if (sum / count == root->val)
            ans++;
        return {sum, count};
    }
};