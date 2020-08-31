/*
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次
请找出数组中任意一个重复的数字

思想：如果没有重复的数字，则数组的下标与元素值相同
*/
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int len = nums.size();
        int res = -1;
        for(int i = 0; i < len; i++){
            while(nums[i] != i){
                int temp = nums[i];
                if(nums[temp] == temp){
                    res = temp;
                    return res;
                }
                nums[i] = nums[temp];
                nums[temp] = temp;
            }
        }
        return res;
    }
};
