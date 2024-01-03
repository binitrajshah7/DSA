class Solution {
public:
    // We use prefix sum approach here to solve it
    // eg: nums = [1,1,1,0,0,1,1,1] then prefix_sum = [1, 2, 3, 2, 1, 2, 3, 4] adding -1 in place of 0
    // Whenever we find curr_sum already present in the prefix sum implies after that index to curr index
    // the subarray has equal 0's and 1's. If sum is 0 implies whole array from start has equal 0's and 1's
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;

        int curr_sum = 0, max_length = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)
                curr_sum--;
            else
                curr_sum++;

            if(mp.find(curr_sum) != mp.end())
                max_length = max(max_length, i - mp[curr_sum]);

            else
                mp[curr_sum] = i;
        }
        return max_length;
    }
};