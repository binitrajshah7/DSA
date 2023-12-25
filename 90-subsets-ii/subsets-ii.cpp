class Solution {
public:
    // Intuition: We always have two choices to make either include a element in subset or not include
    // To take only unique subsets whenever we don't include a element we skip all the occurences of it
    // in sorted order we just skip the decision index for same kind of element which needs to be skipped
    void solve(int index, vector<int> &nums, vector<int> ds, vector<vector<int>> &result){
        // when our index crosses nums size implies we made decision for every element and ds contains our subset
        if(index >= nums.size()){
            result.push_back(ds);
            return;
        }

        // pick
        ds.push_back(nums[index]);
        solve(index+1, nums, ds, result);
        // backtrack
        ds.pop_back();

        // not pick skip all occurences of element to maintain unique subset
        while(index+1 < nums.size() && nums[index] == nums[index+1])
            index++;
        solve(index+1, nums, ds, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> ds;
        solve(0, nums, ds, result);
        return result;
    }
};