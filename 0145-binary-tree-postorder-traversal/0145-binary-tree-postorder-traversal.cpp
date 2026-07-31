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
    void Postorder_traversal(TreeNode* root, vector<int>& postorder) {
        if (root == NULL) {
            return;
        }
        Postorder_traversal(root->left, postorder);
        Postorder_traversal(root->right, postorder);
        postorder.push_back(root->val);
        return;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        Postorder_traversal(root, postorder);
        return postorder;
    }
};