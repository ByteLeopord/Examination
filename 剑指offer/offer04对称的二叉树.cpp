/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* a, TreeNode* b){
        if(a == NULL && b == NULL) 
            return true;
        if(a == NULL || b == NULL || a->val != b->val) 
            return false;
        return solve(a->left, b->right) && solve(a->right, b->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) 
            return true;
        return solve(root->left, root->right);
    }

};
