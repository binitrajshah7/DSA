class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Mark the elements which are out of range [1<=x<=n]
        // and check whether 1 is available or not
        bool is_one_present = false;
        for (int i = 0; i < n; i++){
            if(nums[i] == 1)
                is_one_present = true;
            if (nums[i] < 1 || nums[i] > n)
                nums[i] = 1;
        }

        // If one is not present
        if(!is_one_present)
            return 1;

        // Flag the element with index
        for (int i = 0; i < n; i++)
            nums[abs(nums[i]) - 1] = -(abs(nums[abs(nums[i]) - 1]));

        // find the missing number as the number which is positive means it has not been flagged cause that number was missing
        // so the index + 1 value will be our answer
        for (int i = 0; i < n; i++){
            if(nums[i] > 0)
                return i + 1;
        }
        // if we didn't find any missing then n+1 will be our first positive missing
        return n+1;
    }
};