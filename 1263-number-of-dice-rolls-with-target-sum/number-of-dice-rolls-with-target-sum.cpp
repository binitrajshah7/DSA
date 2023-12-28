class Solution {
public:
    // Intuition: Here we consider all the possibility after rolling a dice
    int MOD = 1e9 + 7;
    int solve(int n, int k, int target, vector<vector<int>> &dp){
        // when no dice left to be rolled
        if(n == 0){
            // if target == 0 then return 1 else 0
            return target==0? 1: 0;
        }

        if(dp[n][target] != -1)
            return (dp[n][target])%MOD;

        int result = 0;
        // all the possibility after rolling a dice
        // this step implies we have rolled a dice one time so remaining dice = n-1
        // and target = target-dice_num
        for(int dice_num=1; dice_num<=k; dice_num++){
            if(dice_num <= target)
                result = (result + solve(n-1, k, target - dice_num, dp))%MOD;
            else
                break;
        }
        return dp[n][target] = result;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        return solve(n, k, target, dp);
    }
};