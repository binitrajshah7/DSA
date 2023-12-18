class Solution {
public:
    // Intuition: Find first and second max similarly first and second smallest then return product of them
    int maxProductDifference(vector<int>& nums) {
        int first_max = 0, second_max = 0;
        int first_min = INT_MAX, second_min = INT_MAX;

        for(auto num: nums){
            if(num < first_min){
                second_min = first_min;
                first_min = num;
            }
            else if(num < second_min)
                second_min = num;

            if(num > first_max){
                second_max = first_max;
                first_max = num;
            }
            else if(num > second_max)
                second_max = num;
        }
        return first_max * second_max - first_min*second_min;
    }
};