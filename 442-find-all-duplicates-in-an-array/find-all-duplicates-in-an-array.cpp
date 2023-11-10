class Solution {
public:
    // Intuition: Flag nums[i] indexed element as negative
    // now in traversal whenever we find a indexed element i.e already negative
    // that implies we got same nums[i] previously so we push it to our result
    vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++){
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0)
            result.push_back(abs(nums[i]));
        else
            nums[index] = nums[index]*-1;
    }
    return result;
}

};