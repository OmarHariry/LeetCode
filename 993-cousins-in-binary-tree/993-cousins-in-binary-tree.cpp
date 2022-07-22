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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>q;
        
        if(!root)
            return false;
        
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            bool a=0,b=0;
            while(size--){
                auto node = q.front();
                q.pop();
                if(node->val == x)
                    a = 1;
                else if(node->val == y)
                    b = 1;
                
                if(node->left && node->right){
                    if((node->left->val == x && node->right->val == y) ||
                       (node->left->val == y && node->right->val == x))
                        return false;
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(a&&b)
                return true;
            if(a || b)
                return false;
            
        }
        return false;
    }
};