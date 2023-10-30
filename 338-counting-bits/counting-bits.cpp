class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        for (int i = 1; i <= n; i++){
            int key = i;
            dp[i] = (key & 1) + dp[(key >> 1)];
        }
        return dp;
    }
};