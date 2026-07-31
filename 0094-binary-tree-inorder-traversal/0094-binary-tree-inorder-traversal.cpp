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
};

/*
   vector<int> inorderTraversal(TreeNode* root) {
       vector<int> inorder;
       if (root == NULL) {
           return inorder;
       }
       stack<TreeNode*> st;
       TreeNode* node = root;
       while (true) {
           if (node != NULL) {
               st.push(node);
               node = node->left;
           } else {
               if (st.empty() == true) {
                   break;
               }
               node = st.top();
               st.pop();
               inorder.push_back(node->val);
               node = node->right;
           }
       }
       return inorder;
   }
};
*/