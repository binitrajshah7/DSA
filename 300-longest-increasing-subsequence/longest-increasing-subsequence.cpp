class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        result.push_back(nums[0]);
        for (int i = 1; i < n; i++){
            if(nums[i] > result.back())
                result.push_back(nums[i]);
            else{
                int low = lower_bound(result.begin(), result.end(),nums[i])- result.begin();
                result[low] = nums[i];
            }
        }
        return result.size();
    }
};