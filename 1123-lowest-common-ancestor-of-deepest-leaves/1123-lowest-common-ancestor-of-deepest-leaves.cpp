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
    int fun(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = fun(root->left);
        int right = fun(root->right);
        return 1 + max(left, right);
    }

    TreeNode* findLCA(TreeNode* root, int depth, int mxdepth) {
        if (root == NULL) {
            return NULL;
        }
        if (depth == mxdepth) {
            return root;
        }

        TreeNode* Left = findLCA(root->left, depth + 1, mxdepth);
        TreeNode* Right = findLCA(root->right, depth + 1, mxdepth);

        if (Left != NULL && Right != NULL) {
            return root;
        }
        if (Left != NULL) {
            return Left;
        }
        return Right;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int mxdepth = fun(root);
        return findLCA(root, 1, mxdepth);
    }
};