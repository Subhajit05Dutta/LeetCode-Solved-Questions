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
    bool ans = false;
   
    void fun(TreeNode* root, int targetSum, int sum) {
        if (root == NULL) {
            return;
        }

        sum += root->val;
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum) {
                ans = true;
            }
            return;
        }
        
        fun(root->left, targetSum, sum);
        fun(root->right, targetSum, sum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) {
            return false;
        }
        fun(root, targetSum, 0);
        return ans;
    }
};