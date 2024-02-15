class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<long long> ps(n, 0);
        ps[0] = nums[0];

        for(int i=1; i<n; i++)
            ps[i] = ps[i-1] + nums[i];

        for(int i=n-1; i>=2; i--){
            if(ps[i]-nums[i] > nums[i])
                return ps[i];
        }

        return -1;
    }
};