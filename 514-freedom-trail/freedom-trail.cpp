class Solution {
public:
    int solve(string ring, string key, int r, int k, vector<vector<int>> &dp){

        if(k == key.size())
            return 0;

        if(dp[r][k] != -1)
            return dp[r][k];
            
        int result = INT_MAX;
        for(int i=0; i<ring.size(); i++){
            if(ring[i] == key[k]){
                int between = abs(r-i);
                int around = ring.size() - abs(r-i);
                int min_dist = min(between, around);

                result = min(result, min_dist + 1 + solve(ring, key, i, k+1, dp));
            }
        }
        return dp[r][k] = result;
    }


    int findRotateSteps(string ring, string key) {
        // index of ring, index of key 
        int r = ring.size();
        int k = key.size();
        vector<vector<int>> dp(r, vector<int> (k, -1));
        return solve(ring, key, 0, 0, dp);
    }
};