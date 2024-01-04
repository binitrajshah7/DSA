class Solution {
public:
    // Intuition: For any freqency greater than 1 it is always possible to reduce it to 0
    // We apply greedy approach here to solve this problem so any number greater than 1 we divide it with 3 & take ceil value
    // eg: 9 -> 3+3+3, 10 -> 3+3+2+2, 11 -> 3+3+3+2, 12 -> 3+3+3+3
    // whenever we increment number by 1 either we break 3 into 2 + 2 or increase 2 to 3
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto e: nums)
            mp[e]++;

        int result = 0;
        for(auto e: mp){
            int freq = e.second;
            if(freq == 1)
                return -1;

            result += freq/3;
            if(freq%3)
                result++;
        }
        return result;
    }
};