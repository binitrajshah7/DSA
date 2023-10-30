class Solution {
public:
    vector<int> countBits(int n) {
        // we will initialise dp of array n+1
        vector<int> dp(n + 1, 0);
        // as we move a element right it will be smaller so we look for number of set bits in smaller element
        dp[0] = 0;
        for (int i = 1; i <= n; i++){
            int key = i;
            dp[i] = (key & 1) + dp[(key >> 1)];
        }
        return dp;
    }
};