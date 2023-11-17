class Solution {
public:
    // Intuition: At every index we have 2 options either buy/not_buy or sell/not_sell
    // We keep a flag whether at a particular index we are allowed to buy or not
    // if we buy at current index we retrict to buy in next index so next index will have two options either to sell or not sell

    int solve(vector<int> &prices, int index, bool buy, vector<vector<int>> &dp){
        if(index == prices.size())
            return 0;

        if(dp[index][buy] != -1)
            return dp[index][buy];
        
        int profit = 0;
        if(buy){
            profit = max((-prices[index] + solve(prices, index+1, 0, dp)), 
                        solve(prices, index+1, 1, dp));
        }
        else{
            profit = max((prices[index] + solve(prices, index+1, 1, dp)),
                        solve(prices, index+1, 0, dp));
        }
        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        // First index will always have permission to buy
        
        // As buy can have only two options 0, 1 so our dp will be dp[n] * [2]

        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return solve(prices, 0, 1, dp);    
    }
};