class Solution {
public:
    // Carry Forward from Buy & Sell Stock 2
    int solve(vector<int> &prices, int index, bool buy, vector<vector<int>> &dp){
        if(index >= prices.size())
            return 0;

        if(dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        if(buy){
            profit = max(-prices[index] + solve(prices, index+1, 0, dp), solve(prices, index+1, 1, dp));
        }   
        else{
            // After selling stock moving to 2 index ahead after cooldown period
            profit = max(prices[index] + solve(prices, index+2, 1, dp), solve(prices, index+1, 0, dp));
        }
        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(prices, 0, 1, dp);
    }
};