class Solution {
public:
    int MOD = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        // bottom up approach
        vector<vector<int>> dp(n+1, vector<int> (target+1, 0));

        // base case when no dice left and target == 0
        dp[0][0] = 1;

        // number of dice
        for(int i=1; i<=n; i++){
            // target
            for(int j=1; j<=target; j++){
                // from recurrence
                int result = 0;
                for(int dice_num=1; dice_num<=k; dice_num++){
                    if(dice_num <= j)
                        result = (result + dp[i-1][j - dice_num])%MOD;
                }
                dp[i][j] = result;
            }
        }

        return (dp[n][target])%MOD;
    }
};