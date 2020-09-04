class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> res;
        int maxsum = pow(6, n);
        vector<vector<int>> dp(n+1, vector<int>(6*n+1, 0));
        for(int i = 1; i <= 6; i++){
            dp[1][i] = 1;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 6*i; j++){
                for(int k = 1; k <= 6; k++){
                    if(j-k <= 0)
                        break;
                    dp[i][j] += dp[i-1][j-k];
                }
            }
        }

        for(int i = n; i <= 6*n; i++){
            res.push_back(dp[n][i]*1.0/maxsum);
        }

        return res;
    }
};
