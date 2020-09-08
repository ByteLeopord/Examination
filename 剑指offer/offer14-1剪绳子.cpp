/*
定义 dp[i] 表示长度i的绳子能得到的最大乘积
则 dp[i] 等于 在绳子区间[0, i)之间剪开的两部分乘积最大值
如果剪开位置为k，则区间分为[0, k)和[k, i)两部分
第一部分长度为k
第二部分长度为i-k, 存在剪和不剪两种情况：
剪的时候值为dp[i-k]，不剪的时候取（i-k)

得到转移方程 dp[i] = max(k*(i-k), k*dp[i-k])
*/
class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        dp[3] = 2;
        for(int i = 4; i <= n; i++){
            for(int k = 2; k < i; k++){
                dp[i] = max(dp[i], max(k*(i-k), k*dp[i-k]));
            }
        }
        return dp[n];
    }
};
