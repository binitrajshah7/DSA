class Solution {
public:
    // Infinite KnapSack problem Recursive approach
    int solve(vector<int> &coins, int index, int amount, vector<vector<int>> &dp){
        if(index == 0){
            if(amount % coins[0] == 0)
                return amount/coins[0];
            return 1e9;
        }

        if(dp[index][amount] != -1)
            return dp[index][amount];

        int not_pick = solve(coins, index-1, amount, dp);
        int pick = INT_MAX;
        if(coins[index] <= amount)
            pick = 1 + solve(coins, index, amount-coins[index], dp);
        return dp[index][amount] = min(pick, not_pick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int result = solve(coins, n-1, amount, dp);
        return result>=1e9? -1: result;
    }  
};