class Solution {
public:
    // Intuition: Two pointer approach
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int left = 0, right = nums.size()-1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum > target)
                right--;
            else if(sum < target)
                left++;
            else
                break;
        }
        return {++left, ++right};
    }
};