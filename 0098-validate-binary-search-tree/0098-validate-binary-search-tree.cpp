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
    void fun(TreeNode* root, vector<int>& res) {
        if (root == NULL) {
            return;
        }
        fun(root->left, res);
        res.push_back(root->val);
        fun(root->right, res);
        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> res;
        fun(root, res);
        for (int i = 1; i < res.size(); i++) {
            if (res[i - 1] < res[i]) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};