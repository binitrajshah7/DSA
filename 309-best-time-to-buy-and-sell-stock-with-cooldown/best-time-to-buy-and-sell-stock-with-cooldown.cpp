class Solution {
public:
    // Carry Forward from Buy & Sell Stock 2
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2, 0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[index] + dp[index+1][0], dp[index+1][1]);
                }   
                else{
                    // After selling stock moving to 2 index ahead after cooldown period
                    profit = max(prices[index] + dp[index+2][1],dp[index+1][0]);
                }
                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }
};