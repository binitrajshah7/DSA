class Solution {
public:
    // Intuition: To get the unique combination every time we sort the array and at a particular level we pick only
    // unique elements if we pick one element we skip similar in next occurences as it is sorted array

    // at a level we consider picking every element and after a pick we just move 1 step forward to next unique element
    void solve(int index, vector<int> &candidates, int target, vector<int> temp, vector<vector<int>> &result){
        // base case
        if(target == 0){
            result.push_back(temp);
            return;
        }

        for(int i=index; i<candidates.size(); i++){
            // if we find same kind of element at a level we just skip it
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            // cause after this element every candidates[i] will be greater than target
            if(candidates[i] > target)
                break;
            // pushing to our datastructure
            temp.push_back(candidates[i]);
            solve(i+1, candidates, target-candidates[i], temp, result);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> result;
        solve(0, candidates, target, temp, result);
        return result;
    }
};