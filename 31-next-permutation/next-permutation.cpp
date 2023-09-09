class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k;
        
        // We will get the last peak element in the array here k points to element just before the peak
        for(k=n-2; k>=0; k--)
            if(nums[k] < nums[k+1])
                break;
        // if k < 0 that means first element was the peak and we need to reverse the whole array
        if(k<0)
            reverse(nums.begin(), nums.end()); 
        else{
            // we will find the element that needs to be swapped with the kth element i.e element just smaller than the peak
            int l;
            for(l=n-1; l>k; l--)
                if(nums[l] > nums[k])
                    break;
            // l points to the index where l is just greater than the left of peak
            swap(nums[l], nums[k]);
            // Now we make the array sorted after we get the new peak i.e after kth index
            reverse(nums.begin()+k+1, nums.end());
        }

    }
};