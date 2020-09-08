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
    vector<vector<int>> res;
    void solve(TreeNode* root, int sum, vector<int>& mark){
        if(root == NULL) 
            return;

        int value = root->val;
        mark.push_back(value);
        sum -= value;
        if(sum == 0 && !root->left && !root->right)
            res.push_back(mark);
        solve(root->left, sum, mark);
        solve(root->right, sum, mark);
        sum += value;
        mark.pop_back();

        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) return {};
        vector<int> mark;
        solve(root, sum, mark);
        return res;
    }
};
