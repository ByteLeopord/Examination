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
    int Depth(TreeNode* root){
        if(root == NULL) 
            return 0;
        return max(Depth(root->left), Depth(root->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) 
            return true;
        int left = Depth(root->left);
        int right = Depth(root->right);

        return abs(left-right) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }
};
