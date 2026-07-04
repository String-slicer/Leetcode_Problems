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
    int height(TreeNode * root){
        if(root==NULL)return 0;
        int ans1= height(root->left);
        int ans2= height(root->right);
        return max(ans1,ans2)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int ans1=height(root->left);
        int ans2=height(root->right);
        int currNode=false;
        if(abs(ans1-ans2)<=1)currNode= true;
        bool leftAns= isBalanced(root->left);
        bool rightAns= isBalanced(root->right);
        return currNode&&leftAns&&rightAns;
    }
};