//动态规划
//第i个字符是否可以与第i-1个字符合并 
//是：在这个字符处的情况数是f(i-2)+f(i-1)
//否：在这个字符处的情况数是f(i-1), 不变
class Solution {
public:
    int translateNum(int num) {
        string nums = to_string(num);
        int len = nums.size();
        vector<int> dp(len+1, 1);
        for(int i = 2; i <= len; i++){
            int mark = 10*(nums[i-2]-'0')+nums[i-1]-'0';
            if(mark < 10 || mark > 25){
                dp[i] = dp[i-1];
            }
            else{
                dp[i] = dp[i-1] + dp[i-2];
            }
        }
        return dp[len];
    }
};
