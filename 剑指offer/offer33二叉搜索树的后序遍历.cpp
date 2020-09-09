class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() == 0) return true;
        int len = postorder.size();
        vector<int> leftpost;
        vector<int> rightpost;
        int index = 0;
        //以根节点即最后一个节点 为分割点 比其小的是左树 大的是右树
        for(; index < len-1; index++){
            if(postorder[index] > postorder[len-1]){
                break;
            }
            leftpost.push_back(postorder[index]);
        }
        for(int j = index; j < len-1; j++){
            if(postorder[j] < postorder[len-1]){
                return false;
            }
            rightpost.push_back(postorder[j]);
        }
        //递归判断左树
        bool left = true;
        if(index > 0){
            left = verifyPostorder(leftpost);
        }
        //递归判断右树
        bool right = true;
        if(index < len-1){
            right = verifyPostorder(rightpost);
        }
        return left && right;
    }
};
