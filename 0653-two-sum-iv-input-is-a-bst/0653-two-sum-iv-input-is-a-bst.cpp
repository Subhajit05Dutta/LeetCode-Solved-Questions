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
    bool fun(TreeNode* root, int k, unordered_set<int>& st) {
        if (root == NULL) {
            return false;
        }
        int need = k - root->val;
        if (st.find(need) != st.end()) {
            return true;
        }

        st.insert(root->val);

        bool c1 = fun(root->left, k, st);
        bool c2 = fun(root->right, k, st);
        return c1 || c2;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return fun(root, k, st);
    }
};