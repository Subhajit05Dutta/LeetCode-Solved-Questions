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
    void Inorder(TreeNode* root,vector<int>&inorder){
        if(root==NULL){
            return;
        }
        Inorder(root->left,inorder);
        inorder.push_back(root->val);
        Inorder(root->right,inorder);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        if(root==NULL){
            return inorder;
        }
        Inorder(root,inorder);
        return inorder;
    }
};

/*
 //Recursive Approach

 void Inorder_traversal(TreeNode* root, vector<int>& inorder) {
        if (root == NULL) {
            return;
        }
        Inorder_traversal(root->left, inorder);
        inorder.push_back(root->val);
        Inorder_traversal(root->right, inorder);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        Inorder_traversal(root, inorder);
        return inorder;
    }
*/