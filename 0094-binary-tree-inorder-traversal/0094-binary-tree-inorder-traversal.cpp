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
    void solve(vector<int>&order,TreeNode* root){
        if(root==NULL)return;
        solve(order,root->left);
        order.push_back(root->val);
        solve(order,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>order;
        solve(order,root);
        return order;
    }
};