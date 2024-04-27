class Solution {
public:
    // Note: Here r and k is (index of ring, index of key)
    // Intuition: For every kth index character if key we check for all the possibilities
    // if ring's character matches keys kth character then we take the minimum distance to reach there
    // greedy approach and call for the next k+1th character check
    int solve(string ring, string key, int r, int k, vector<vector<int>> &dp){

        // if all the character of key is found then we return 0
        if(k == key.size())
            return 0;

        // memoization
        if(dp[r][k] != -1)
            return dp[r][k];

        int result = INT_MAX;
        
        // we are considering every occurence of character but apply greedy in next step
        for(int i=0; i<ring.size(); i++){
            // found key character in ring
            if(ring[i] == key[k]){
                
                // between & around distance think it as clockwise and anticlockwise distance from i
                int between = abs(r-i);
                int around = ring.size() - abs(r-i);
                int min_dist = min(between, around);

                // as picking the character is itself 1 op, and distance is min_dist
                result = min(result, min_dist + 1 + solve(ring, key, i, k+1, dp));
            }
        }

        // memoize and return
        return dp[r][k] = result;
    }


    int findRotateSteps(string ring, string key) { 
        int r = ring.size();
        int k = key.size();
        vector<vector<int>> dp(r, vector<int> (k, -1));
        return solve(ring, key, 0, 0, dp);
    }
};