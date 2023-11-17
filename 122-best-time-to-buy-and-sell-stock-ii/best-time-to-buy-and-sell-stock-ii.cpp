class Solution {
public:
    // Intuition: At every index we have 2 options either buy/not_buy or sell/not_sell
    // We keep a flag whether at a particular index we are allowed to buy or not
    // if we buy at current index we retrict to buy in next index so next index will have two options either to sell or not sell

    int maxProfit(vector<int>& prices) {
        // First index will always have permission to buy
        // As buy can have only two options 0, 1 so our dp will be dp[n] * [2]
        int n = prices.size();
        vector<vector<int>> dp(prices.size()+1, vector<int> (2, 0));

        // Base case when index=prices.size() return 0;
        dp[n][0] = 0;
        dp[n][1] = 0;

        // write changing parameters in reverse order bottom up
        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if(buy){
                    profit = max(-prices[index] + dp[index+1][0], dp[index+1][1]);
                }
                else{
                    profit = max(prices[index] + dp[index+1][1], dp[index+1][0]);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];    
    }
};