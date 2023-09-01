class Solution {
public:
    void combination_recursion(vector<int> candidates, int target, int index, vector<int> &temp, vector<vector<int>> &result){
        
        // when index goes out of bound 2 scenario may occur
        if(index == candidates.size()){
            // target is 0 i.e we found possible combination that can sum up to target
            if(target == 0)
                result.push_back(temp);
            // we might not get target 0 so we simply return
            return;
        }

        // Picking up an element
        if(target >= candidates[index]){
            // pushing our element to our data structure
            temp.push_back(candidates[index]);
            // as we can pick a element multiple times we will not increase index but our target will come down
            combination_recursion(candidates, target-candidates[index], index, temp, result);
            // when we backtrack to get we pop the picked element 
            temp.pop_back();
        }
        // not picking up
        // if we don't pick we will increase the index and move to next element as current element makes target less than 0
        combination_recursion(candidates, target, index+1, temp, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        combination_recursion(candidates, target, 0, temp, result);
        return result;
    }
};