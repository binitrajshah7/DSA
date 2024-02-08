class Solution {
public:
    // Intuition is same like coin change problem where we can decide whether to pick a coin or not
    // since it has to be subtracted from perfect square number so our possible coins can be i = 1, 2, 3, ...
    // we just have to keep a check in place that i*i < n then only we can consider picking or not picking a number
    // for perfect squares
    int get_min_count(int n, int i, vector<int> &dp){
        if (n == 0)     
            return 0;

        if(dp[n])
            return dp[n];

        if (i*i <= n){
            // as we can pick a coin multiple times so we decrease our target and keep pointer to same
            int pick = 1+get_min_count(n-i*i, i, dp);
            // as we don't pick we will move forward in index keeping target same
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