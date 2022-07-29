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
    bool dfs(TreeNode*root,long long minVal,long long maxVal){
        if(!root)
            return true;
        
        if(root->val > minVal && root->val < maxVal)
            return dfs(root->left, minVal,root->val) && dfs(root->right, root->val, maxVal);
        
        return false;
        
        
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,(long long)INT_MIN*2,(long long)INT_MAX*2);
    }
};