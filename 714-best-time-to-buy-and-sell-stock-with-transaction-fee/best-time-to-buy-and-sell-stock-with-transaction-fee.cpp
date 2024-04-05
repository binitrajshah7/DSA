class Solution {
public:
    // Intuition: Similar to Buy & Sell Stock II just a slight change that when we complete
    // or start a transaction subtract a transaction fee
    int solve(vector<int> &prices, int index, bool buy, vector<vector<int>> &dp, int &fee){
        if(index == prices.size())
            return 0;

        if(dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        // has permission to buy but may or may not buy
        if(buy){
            profit = max((-prices[index] + solve(prices, index+1, 0, dp, fee)), 
                         (solve(prices, index+1, 1, dp, fee)));
        }
        // can't buy but has permission to sell but may or may not sell
        else{
            // if sells than 1 transaction is closed so transaction fee applied along with profit
            profit = max((prices[index] - fee + solve(prices, index+1, 1, dp, fee)), 
                         (solve(prices, index+1, 0, dp, fee)));
        }

        return dp[index][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        // First index will always have permission to buy        
        // As buy can have only two options 0, 1 so our dp will be dp[n] * [2]
        vector<vector<int>> dp(prices.size(), vector<int> (2, -1));
        return solve(prices, 0, 1, dp, fee);
    }
};