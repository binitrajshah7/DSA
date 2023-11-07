class Solution {
public:
    // so we are just keeping track of unique elements from our result
    // whenever in our traversal we get unique element we replace it with our result
    // and increment our result
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int result = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[result-1] != nums[i]){
                nums[result] = nums[i];
                result++;
            }
        }
        return result;
    }
};