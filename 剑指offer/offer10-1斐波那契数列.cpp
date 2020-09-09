class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        const int mod = 1000000007;
        int dp_1 = 1, dp_2 = 0;
        for(int i = 2; i <= n; i++){
            int sum = (dp_1 + dp_2)%mod;
            dp_2 = dp_1;
            dp_1 = sum;
        }
        return dp_1;
    }
};
