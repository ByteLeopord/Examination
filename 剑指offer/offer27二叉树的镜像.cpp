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
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        TreeNode* node = new TreeNode(root->val);
        node->left = mirrorTree(root->right);
        node->right = mirrorTree(root->left);
        return node;
    }
};
