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
    TreeNode* help(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright){
        if(preleft > preright || inleft > inright) return NULL;

        TreeNode* node = new TreeNode(preorder[preleft]);
        
        int pindex = preleft+1, iindex;
        for(int i = inleft; i <= inright; i++){   //根据中序遍历数组找到前序遍历数组的分割点
            if(inorder[i] == node->val){
                iindex = i;
                break;
            }
            pindex++;
        }

        node->left = help(preorder, inorder, preleft+1, pindex-1, inleft, iindex-1);
        node->right = help(preorder, inorder, pindex, preright, iindex+1, inright);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int len = preorder.size();
        return help(preorder, inorder, 0, len-1, 0, len-1);
    }
};
