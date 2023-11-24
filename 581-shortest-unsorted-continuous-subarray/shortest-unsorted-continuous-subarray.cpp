class Solution {
public:
    // Intuition: We can have conflicts in our array conflict is when we find peak or dip i.e next element is smaller or previous element is greater
    // So among all the conflicted zone we will store the minimum value and maximum value and in the next iteration we will find their correct 
    // position in the array and return the length difference between their correct positions
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n==1)    return 0;
        int min_conflict = INT_MAX, max_conflict = INT_MIN;

        for(int i=0; i<n; i++){
            if(i==0){
                if(nums[i] > nums[i+1]){
                    min_conflict = min(min_conflict, nums[i]);
                    max_conflict = max(max_conflict, nums[i]);
                }
            }
                
            else if(i==n-1){
                if(nums[i]<nums[i-1]){
                    min_conflict = min(min_conflict, nums[i]);
                    max_conflict = max(max_conflict, nums[i]);
                }
            }
                
            else{
                if(nums[i] > nums[i+1] || nums[i]<nums[i-1]){
                    min_conflict = min(min_conflict, nums[i]);
                    max_conflict = max(max_conflict, nums[i]);
                }
            }
        }

        if(min_conflict==INT_MAX || max_conflict==INT_MIN)
            return 0;


        int left, right;
        for(left=0; left<n && nums[left]<=min_conflict; left++);
        for(right=n-1; right>=0 && nums[right]>=max_conflict; right--);
              
        return right-left+1;
    }
};