/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using namespace std;
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "[";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node){
                res += to_string(node->val) + ",";
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            else{
                res += "null,";
            }
        }
        int len = res.size();
        res[len-1] = ']';
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return NULL;
        int len = data.size();
        int remindex = 1;
        vector<string> mark;
        for (int i = 1; i < len; i++){
            if (data[i] == ',' || data[i] == ']'){
                string temp = data.substr(remindex, i - remindex);
                mark.push_back(temp);
                remindex = i + 1;
            }
        }
        TreeNode* head = new TreeNode(std::stoi(mark[0]));
        queue<TreeNode*> q;
        q.push(head);
        remindex = 1;
        int n = mark.size();
        while (!q.empty() && remindex < n){
            TreeNode* node = q.front();
            q.pop();
            if (mark[remindex] != "null"){
                node->left = new TreeNode(std::stoi(mark[remindex]));
                q.push(node->left);
            }
            remindex++;
            if (remindex >= n) break;
            if (mark[remindex] != "null"){
                node->right = new TreeNode(std::stoi(mark[remindex]));
                q.push(node->right);
            }
            remindex++;
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
