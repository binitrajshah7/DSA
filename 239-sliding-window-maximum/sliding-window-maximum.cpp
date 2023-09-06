class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {    
        deque<int> dq;
        vector<int> result;
        // Intuition is to keep maximum element of current window at first of our deque
        for(int i=0; i<nums.size(); i++){
            // remove all the element out of your window size from deque
            if(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
            // and remove all the element from back which is smaller than the current element as it won't help for further windows
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            // if our i is more than window size then we start pushing back result
            if(i >= k-1)
                result.push_back(nums[dq.front()]);
        }
        return result;
    }
};