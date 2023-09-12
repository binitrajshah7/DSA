class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        // we will make a max heap out of all elements in the array
        for(int i=0; i<nums.size(); i++)
            pq.push(nums[i]);
        // then we will pop k-1 element from the max heap
        for (int i = 0; i < k-1; i++)
            pq.pop();
        // now top of max heap is our answer 
        return pq.top();
    }
};