class Solution {
public:
    // Tabulation Approach
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));

        for(int t=0; t<=amount; t++){
            if(t%coins[0] == 0)
                dp[0][t] = t/coins[0];
            else
                dp[0][t] = 1e9;
        }

        for(int index=1; index<n; index++){
            for(int target=0; target<=amount; target++){
                int not_pick = dp[index-1][target];
                int pick = INT_MAX;
                if(coins[index] <= target)
                    pick = 1 + dp[index][target-coins[index]];
                dp[index][target] = min(pick, not_pick);
            }
        }
        int result = dp[n-1][amount];
        return result>=1e9? -1: result;
    }  
};