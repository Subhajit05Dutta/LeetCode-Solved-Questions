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
    bool ans=false;
    int sum=0;
    void res_sum(TreeNode* root, int targetSum,int sum){
        if(root==NULL){
            return;
        }
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                ans=true;
                return;
            }
        }
        res_sum(root->left,targetSum,sum);
        res_sum(root->right,targetSum,sum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        res_sum(root,targetSum,sum);
        return ans;
    }
};