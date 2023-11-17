class Solution {
public:
    

    int maxProfit(int k, vector<int>& prices) {
        // solve(prices, index, can_buy, capacity)
        int n = prices.size();

        // dp[n] * [2] * [k]
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        /*
        // If index is anything and buy is anything but cap is 0 then no transaction so profit 0
        for(int i=0; i<n; i++){
            for(int buy=0; buy<=1; buy++){
                dp[i][buy][0] = 0;
            }
        }

        // For any index out of bound profit will be 0
        for(int buy=0; buy<=1; buy++){
            for(int cap=0; cap<=2; cap++){
                dp[n][buy][cap] = 0;
            }
        }
        */
        // As we have initialised our dp to 0 itself so writing base cases doesn't makes sense just for reference
        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int capacity=1; capacity<=k; capacity++){
                    int profit = 0;
                    // buy or not buy
                    if(buy){
                        // if buy then we invested money so we take profit as negative not buy then we simply go to next index with can buy as true
                        profit = max(-prices[index] + dp[index+1][0][capacity], dp[index+1][1][capacity]);
                    }   
                    else{
                        // if sell then we complete our 1 transaction so we reduce the capacity by 1
                        profit = max(prices[index] + dp[index+1][1][capacity-1], dp[index+1][0][capacity]);
                    }
                    dp[index][buy][capacity]=profit;
                }
            }
        }
        return dp[0][1][k];
    }
};