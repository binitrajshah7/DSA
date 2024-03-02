class Solution {
public:
    // Intuition: Take two pointers pointing to two extreme sides
    // Now whatever absolute value is greater of the boundary push it to the last element
    // and move pointer back to check for next position
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int left = 0, right=result.size()-1;
        for(int i=result.size()-1; i>=0; i--){
            if(abs(nums[right]) > abs(nums[left]))
                result[i] = nums[right] * nums[right--];
            else
                result[i] = nums[left] * nums[left++];
        }
        return result;
    }
};