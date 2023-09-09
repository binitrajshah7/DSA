class Solution {
public:
    void sortColors(vector<int>& nums) {
        // we split 3 windows low, mid, high
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high){
            // mid is our main pointer that increases while going further
            switch(nums[mid]){
                // if we find 0 i.e we will increase low window size and mid window size
                case 0:
                    swap(nums[low++], nums[mid++]);
                    break;
                // if we find 1 simply increase only mid window size
                case 1:
                    mid++;
                    break;
                // if we find 2 we will swap 2 with last window of high and increase 2's window size
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
        
    }
};