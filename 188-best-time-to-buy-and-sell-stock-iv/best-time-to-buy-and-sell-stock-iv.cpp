class Solution {
public:
    // Carry forward from buy and stock III
    // Intuition same as Buy & Sell Stock II but we keep an additional check for transaction capacity
    int solve(vector<int> &prices, int index, bool buy, int capacity, vector<vector<vector<int>>> &dp){
        if(capacity == 0 || index == prices.size())
            return 0;
        
        if(dp[index][buy][capacity] != -1)
            return dp[index][buy][capacity];

        int profit = 0;
        // buy or not buy
        if(buy){
            // if buy then we invested money so we take profit as negative not buy then we simply go to next index with can buy as true
            profit = max(-prices[index] + solve(prices, index+1, 0, capacity, dp),
                        solve(prices, index+1, 1, capacity, dp));
        }   
        else{
            // if sell then we complete our 1 transaction so we reduce the capacity by 1
            profit = max(prices[index] + solve(prices, index+1, 1, capacity-1, dp),
                        solve(prices, index+1, 0, capacity, dp));
        }
        return dp[index][buy][capacity]=profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        // solve(prices, index, can_buy, capacity)
        int n = prices.size();

        // dp[n] * [2] * [k]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(prices, 0, 1, k, dp);
    }
};