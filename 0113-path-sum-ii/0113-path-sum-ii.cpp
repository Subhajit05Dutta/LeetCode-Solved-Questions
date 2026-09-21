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
public:
    void fun(TreeNode* root, int targetSum, int sum, vector<int>& path,
             vector<vector<int>>& ans) {
        if (root == NULL) {
            return;
        }
        sum += root->val;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (targetSum == sum) {
                ans.push_back(path);
            }
            path.pop_back();
            return;
        }

        fun(root->left, targetSum, sum, path, ans);
        fun(root->right, targetSum, sum, path, ans);
        path.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        fun(root, targetSum, 0, path, ans);
        return ans;
    }
};