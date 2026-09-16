/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    int fun(TreeNode* n, TreeNode* n1, TreeNode* n2) {
        if (n == NULL) {
            return 0;
        }
        int left = fun(n->left, n1, n2);
        int right = fun(n->right, n1, n2);
        int self = 0;
        if (n == n1 || n == n2) {
            self = 1;
        }
        int total = left + right + self;
        if (total == 2 && ans == NULL) {
            ans = n;
        }
        return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }
        fun(root, p, q);
        return ans;
    }
};