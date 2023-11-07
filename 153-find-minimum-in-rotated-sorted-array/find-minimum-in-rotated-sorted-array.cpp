class Solution {
public:
    // Intuition is same as search in rotated sorted array
    // at any given mid while binary search it is guaranteed that one half will be sorted
    int findMin(vector<int>& nums) {
        int low=0, high=nums.size()-1;
        int result = INT_MAX;

        while(low<=high){
            // Considering whole array if first element is smaller 
            // than last then we will return first element
            if(nums[low] < nums[high]){
                result = min(result, nums[low]);
                break;
            }
            
            int mid = (low+high)/2;
            // if left half is sorted then first element of left half will be our potential answer
            // and we go on right half after this
            if(nums[low] <= nums[mid]){
                result = min(result, nums[low]);
                low = mid+1;
            }
            else{
                result = min(result, nums[mid]);
                high = mid-1;
            }
        }
        return result;
    }
};