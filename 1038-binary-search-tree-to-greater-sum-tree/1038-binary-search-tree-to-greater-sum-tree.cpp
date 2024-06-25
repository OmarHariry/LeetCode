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
    void inorder(TreeNode*root, vector<int>& traversal) {
        if(!root)
            return;
        inorder(root->left, traversal);
        traversal.push_back(root->val);
        inorder(root->right, traversal);
    }
    void replaceValues(TreeNode* root, vector<int>& traversal) {
        if (!root) 
            return;
        
        replaceValues(root->left, traversal);
        
        int sum = 0;
        for(int i : traversal) {
            if (i >= root->val)
                sum += i;
            else
                break;
        }
        root->val = sum;
        replaceValues(root->right, traversal);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> traversal;
        inorder(root, traversal);
        reverse(traversal.begin(), traversal.end());
        
        replaceValues(root, traversal);
        return root;
    }
};