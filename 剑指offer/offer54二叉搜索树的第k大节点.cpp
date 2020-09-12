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
    int mark;
    void intersort(TreeNode* root, int& k){
        if(root == NULL) return;

        intersort(root->right, k);
        if(k == 0) return;
        if(k == 1){
            mark = root->val;
        }
        k--;
        intersort(root->left, k);
    }
    int kthLargest(TreeNode* root, int k) {
        intersort(root, k);
        return mark;
    }
};
