class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int conflict = 0;
        for(int i=0; i<n-1; i++){
            
            if(nums[i] > nums[i+1]){
                conflict++;
                if(conflict > 1)
                    return false;

                // carrying maximum possible after first conflicted boundary
                if(i>0 && nums[i-1] > nums[i+1]){
                    nums[i+1] = nums[i];
                }

            }

        }
        return true;
    }
};