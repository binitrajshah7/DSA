class Solution {
public:
    // Intuition: Chup chap Pepcoding kaa video dekh
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        vector<unordered_map<long, long>> maps(n+1);
        int result = 0;

        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                long common_difference = (long) nums[i] - (long) nums[j];

                int aps_ending_on_j = maps[j][common_difference];
                int aps_ending_on_i = maps[i][common_difference];

                result += aps_ending_on_j;
                maps[i][common_difference] = aps_ending_on_i + aps_ending_on_j + 1;
            }
        }
        return result;
    }
};