class Solution {
public:
    void combination_recursion(vector<int> candidates, int target, int index, vector<int> &temp, vector<vector<int>> &result){
        if(index == candidates.size()){
            if(target == 0)
                result.push_back(temp);
            return;
        }

        if(target >= candidates[index]){
            temp.push_back(candidates[index]);
            combination_recursion(candidates, target-candidates[index], index, temp, result);
            temp.pop_back();
        }
        combination_recursion(candidates, target, index+1, temp, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        combination_recursion(candidates, target, 0, temp, result);
        return result;
    }
};