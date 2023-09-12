class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        // Pushing every element in set 
        for (int i = 0; i < n; i++)
            s.insert(nums[i]);

        int result = 0;

        // for every num we check whether it makes longes subsequence or not
        for (auto num : nums){
            // check whether it is the first element to start the subsequence or not
            // if element less than current num is available then we will start from 
            // that element or might have counted for that element so current num is ignored
            if(s.find(num-1) == s.end()){
                int curr = 0;
                // Checking for subsequence 
                while(true){
                    if(s.find(num++) != s.end())
                        curr++;
                    else
                        break;
                    result = max(result, curr);
                }
            }
        }
        return result;
    }
};