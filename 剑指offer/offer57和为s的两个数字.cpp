class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum > target){
                right--;
            }
            else if(sum < target){
                left++;
            }
            else{
                return{nums[left], nums[right]};
            }
        }
        return {-1, -1};
    }
};
