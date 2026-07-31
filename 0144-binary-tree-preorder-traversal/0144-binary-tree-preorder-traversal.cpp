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
// Recursive Approach
 void Preorder_traversal(TreeNode* root,vector<int>&preorder){
    if(root==NULL){
        return;
    }
    preorder.push_back(root->val);
    Preorder_traversal(root->left,preorder);
    Preorder_traversal(root->right,preorder);
    return;
 }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        Preorder_traversal(root, preorder);
        return preorder;
    }
};
/*
    // Iterative Approach
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if (root == NULL) {
            return preorder;
        }
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            root = st.top();
            st.pop();
            preorder.push_back(root->val);
            // As Stack is LIFO data structure so we push the right node first,
            // then the left node.
            if (root->right != NULL) {
                st.push(root->right);
            }
            if (root->left != NULL) {
                st.push(root->left);
            }
        }
        return preorder;
    }

*/
 