class Solution {
public:
    // total sum of n elements is n*(n+1)/2 so we calculate all element sum from nums and subtract it with t_sum
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int t_sum = n*(n+1)/2;
        int sum=0;
        for(int i=0; i<n; i++)
            sum += nums[i];
        return t_sum-sum;
    }
};