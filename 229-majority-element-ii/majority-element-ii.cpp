class Solution {
public:
    // Intuition: As we need to find elements with frequency minimum n/3 implies we can get atmost 2 n/3 frequency majority element.
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int nums1, nums2;

        int count1 = 0, count2 = 0;

        // Getting 2 major element with max frequency
        for(int i=0; i<n; i++){
            // if equal to first element then vote for first
            if(nums[i] == nums1)
                count1++;
            // if equal to second element then vote for second
            else if(nums[i] == nums2)
                count2++;
            // if matches no string then we check if any of our count is 0 i.e we can assign it to 
            // nums1 or nums2 as it might be the potential candidate further
            else if(count1 == 0){
                nums1 = nums[i];
                count1++;
            }
            else if(count2 == 0){
                nums2 = nums[i];
                count2++;
            }
            // if don't match both potential candidate and both potential candidate's count is greater than 0
            // then we decrease both's count
            else{
                count1--;
                count2--;
            }
        }

        // getting frequency for both potential candidate
        count1 = 0, count2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == nums1)
                count1++;
            else if(nums[i] == nums2)
                count2++;
        }

        // check & push
        vector<int> result;
        if(count1 > (n/3))
            result.push_back(nums1);
        if(count2 > (n/3))
            result.push_back(nums2);
        return result;
    }
};