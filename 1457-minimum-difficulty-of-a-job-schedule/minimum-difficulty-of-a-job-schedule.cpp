class Solution {
public:
    int dp[301][301][11];

    int f(int ind, int curr_max, int d, vector<int>& nums) {
        if(d == 0) return 1e9;
        if(ind >= nums.size()) 
            return d == 1 ? nums[curr_max] : 1e9;
        if(dp[ind][curr_max][d] != -1) 
            return dp[ind][curr_max][d];

        // At each index, we have two option:
        // 1. Either carry the current task in previous day
        // 2. Finish the day and start current task in new day
        int continue_day = f(ind+1, nums[ind] > nums[curr_max] ? ind : curr_max, d, nums);
        // while finishing the day, we took maximum difficulty among all previous tasks 
        int end_day = nums[curr_max] + f(ind+1, ind, d-1, nums); 

        return dp[ind][curr_max][d] = min(continue_day, end_day);
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size()) return -1;
        memset(dp, -1, sizeof(dp));
        return f(1, 0, d, jobDifficulty);
    }
};