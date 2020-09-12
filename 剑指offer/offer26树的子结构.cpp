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
    bool solve(TreeNode* A, TreeNode* B){
        if(B == NULL) 
            return true;
        if(A == NULL)
            return false;
        if(A->val != B->val)
            return false;
        return solve(A->left, B->left) && solve(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == NULL || B == NULL)
            return false;
        if(solve(A, B)) 
            return true;
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
