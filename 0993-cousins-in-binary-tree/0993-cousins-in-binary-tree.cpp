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
    TreeNode* help(TreeNode* root, int val, int depth, int& level) {
        if (root == NULL) {
            return NULL;
        }
        if ((root->left && root->left->val == val) ||
            (root->right && root->right->val == val)) {
            level = depth;
            return root;
        }
        TreeNode* left = help(root->left, val, depth + 1, level);
        if (left != NULL) {
            return left;
        }
        TreeNode* right = help(root->right, val, depth + 1, level);
        if (right != NULL) {
            return right;
        }
        return NULL;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int xdepth = -1;
        int ydepth = -1;
        TreeNode* X_par = help(root, x, 0, xdepth);
        TreeNode* Y_par = help(root, y, 0, ydepth);
        if (xdepth != ydepth || X_par == Y_par)
        return false;
        return true;
    }
};