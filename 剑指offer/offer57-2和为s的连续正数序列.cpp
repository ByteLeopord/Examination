/*
    滑动指针
*/
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        // if(target < 3) return {-1, -1}; 
        int left = 1, right = 2;
        vector<vector<int>> res;
        int sum = left + right;
        while(right < target){ 
            if(sum < target){
                right++;
                sum += right;
            }
            else if(sum > target){
                sum -= left;
                left++;
            }
            else if(sum == target && right-left >= 1){
                vector<int> temp;
                for(int i = left; i <= right; i++){
                    temp.push_back(i);
                }
                res.push_back(temp);
                sum -= left;
                left++;
            }
        }
        return res;
    }
};
