/*
dp_0: 当前没有持有股票 - 卖出或未买入
dp_1：当前持有股票 - 买入
初始持有价钱为0， 所以dp_1为负，取最大值即价格最小的买入
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int dp_0, dp_1;
        dp_1 = -prices[0];    //持有
        dp_0 = 0;
        int len = prices.size();
        for(int i = 1; i < len; i++){
            dp_0 = max(dp_0, dp_1+prices[i]);
            dp_1 = max(dp_1, -prices[i]);
        }
        return dp_0;
    }
};
