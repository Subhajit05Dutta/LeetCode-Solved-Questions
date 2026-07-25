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
    vector<vector<int>> ans;
    int sum = 0;
    void fun(TreeNode* root, int targetSum, vector<int>& temp) {
        if (root == NULL) {
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        if ((root->left == NULL && root->right == NULL) && (sum == targetSum)) {
            ans.push_back(temp);
            sum -= root->val;
            temp.pop_back();
            return;
        }
        fun(root->left, targetSum, temp);
        fun(root->right, targetSum, temp);
        sum -= root->val;
        temp.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        fun(root, targetSum, temp);
        return ans;
    }
};