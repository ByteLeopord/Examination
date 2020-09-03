/*
初始状态：dp[0] = 1, dp[1] = 1, dp[2] = 2
动态转换方程：dp[n] = dp[n-1] + dp[n-2]
*/
class Solution {
public:
    int const mod = 1000000007;   //取余常量
    int numWays(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int dp_1 = 2, dp_2 = 1;
        int res = 0;
        for(int i = 3; i <= n; i++){
            res = (dp_1 + dp_2) % mod;
            dp_2 = dp_1;
            dp_1 = res;
        }
        return res % mod;
    }
};
