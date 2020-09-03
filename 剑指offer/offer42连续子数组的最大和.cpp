/*
dp[i]意义：从0到i这个子数组的最大和
maxsub记录最大的dp[i]
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        int maxsub = dp[0];
        for(int i = 1; i < len; i++){
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            if(dp[i] > maxsub){
                maxsub = dp[i];
            }
        }
        return maxsub;
    }
};
