class Solution {
public:
    int get_min_count(int n, int i, vector<int> &dp){
        if (n == 0)     
            return 0;

        if(dp[n])
            return dp[n];

        if (i*i <= n){
            int pick = 1+get_min_count(n-i*i, i, dp);
            int not_pick = get_min_count(n, i+1, dp);
            return dp[n] = min(pick, not_pick);
        }
        return 1e5;
    }
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        return get_min_count(n, 1, dp);
    }
};