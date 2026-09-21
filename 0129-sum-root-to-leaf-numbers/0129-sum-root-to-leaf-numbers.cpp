/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    void fun(TreeNode* root,int num,int &ans){
        if(root==NULL){
            return;
        }
        num=num*10+root->val;
        if(root->left==NULL && root->right==NULL){
            ans+=num;
           return;
        }

        fun(root->left,num,ans);
        fun(root->right,num,ans);
       
        return;

    }
    int sumNumbers(TreeNode* root) {
        fun(root,0,ans);
        return ans;
    }
};