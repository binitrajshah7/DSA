class Solution {
public:
    void subset_recur(vector<int> nums, vector<int> &temp, vector<vector<int>> &result, int idx){
        // when index reaches last it will be our base condition
        if(idx == nums.size()){
            result.push_back(temp);
            return;
        }
        // picking an element
        temp.push_back(nums[idx]);
        subset_recur(nums, temp, result, idx+1);
        // backtracking
        temp.pop_back();
        // not picking and element
        subset_recur(nums, temp, result, idx+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        subset_recur(nums, temp, result, 0);
        return result;
    }
};