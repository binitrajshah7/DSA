class Solution {
public:
    void permute_recursive(int index, vector<int> &nums, vector<vector<int>> &result){
        // when index becomes nums.size() that means nums have been swapped maximum time for 1st indexed element
        if(index == nums.size()){
            result.push_back(nums);
            return;
        }
        
        // swapping with every possible value from index to n-1th element
        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            permute_recursive(index+1, nums, result);
            // backtracking and making it same
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permute_recursive(0, nums, result);
        return result;
    }
};