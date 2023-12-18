class Solution {
public:
    // Intuition: Same like permutation 1 we keep on swapping for every index i.e use all possible value we can use for a particular index
    // tweak here is we should only use unique element so we take a freq_map whenever we have some element in our map whose freq > 0
    // then we push it to our current permutation and decrease it's count in freq_map and call for next dfs
    void solve(unordered_map<int, int> &freq_map, vector<int> &permutation, vector<vector<int>> &result, vector<int> &nums){

        if(permutation.size() == nums.size()){
            result.push_back(permutation);
            return;
        }
        
        for(auto unique: freq_map){
            if(unique.second > 0){
                permutation.push_back(unique.first);
                freq_map[unique.first]--;
                solve(freq_map, permutation, result, nums);
                // backtracking
                freq_map[unique.first]++;
                permutation.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> freq_map;
        for(auto num: nums)
            freq_map[num]++;
        
        vector<vector<int>> result;
        vector<int> permutation;
        solve(freq_map, permutation, result, nums);
        return result;
    }
};