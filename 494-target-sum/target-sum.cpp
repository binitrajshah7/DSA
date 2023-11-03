class Solution {
public:
    // Intuition: For every nums[i] we have two options either to take positive or negative of it and our index should
    // always move forward
    int get_total_ways(vector<int> nums, int target, int index, int sum, unordered_map<string, int> &dp){
        // whenever sum is equal to target and index == n i.e we have to consider 
        // every element either positive or negative 
        if (sum == target && index == nums.size())
            return 1;
        // if index crosses nums size then we return 0
        if(index >= nums.size())
            return 0;

        // to memoize this solution we have to take a map that will store key as index_sum 
        // so for every nums[i] we check if this sum already existed for this index
        string key = to_string(index) + "_" + to_string(sum);

        if(dp.find(key)!=dp.end())
            return dp[key];

        // taking nums[i] as positive so we add to our sum and our index will always move forward
        int positive = get_total_ways(nums, target, index+1, sum+nums[index], dp);
        int negative = get_total_ways(nums, target, index+1, sum-nums[index], dp);
        
        // since we have to take all possible count we will add positive and negative
        return dp[key] = positive + negative;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> dp;
        return get_total_ways(nums, target, 0, 0, dp);
    }
};