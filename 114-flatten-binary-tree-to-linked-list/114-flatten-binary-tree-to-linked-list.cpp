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
    TreeNode* rightMost(TreeNode*root){
        if(!root->right)
            return root;
        
        return rightMost(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root)
            return;
        
        while(root){
            if(root->left){
                TreeNode*rightmost = rightMost(root->left);
                TreeNode*right = root->right;
                
                root->right = root->left;
                root->left = NULL;
                rightmost->right = right;
            }
            root = root->right;
        }
        
    }
};