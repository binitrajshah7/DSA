class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0, p2 = n-1;
        for(int i = 0;i<=p2; i++)
        {
            if(nums[i] == 0)
            {
                swap(nums[i], nums[p1]);
                p1++;
            }
            else if(nums[i] == 2 )
            {
                swap(nums[i], nums[p2]);
                p2--;
                i--;
            }     
        }
    }
};