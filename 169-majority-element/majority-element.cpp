class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // as we know there is a majority element for sure
        int result, count = 0;
        // so we voting technique like
        for(int i=0; i<nums.size(); i++){
            // when count is 0 we will consider our current element as our majority element
            if(count == 0){
                result = nums[i];
                count++;
            }
            // else we will check if our current element is same as our previously declared majority element
            // if yes then we will increase it's count 
            else if(nums[i] == result)
                count++;
            // else we will decrease it's count if count becomes 0 again we will declare new nums[i] as
            // potential to be our majority element
            else
                count--;
        }
        return result;
    }
};