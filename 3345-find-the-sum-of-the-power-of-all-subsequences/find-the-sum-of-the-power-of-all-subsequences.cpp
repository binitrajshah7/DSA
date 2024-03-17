typedef long long ll;
class Solution {
public:

    long long power(int n){
        if(n <= 1) return (n+1);
        long long res = power(n/2);
        if(n%2) 
            return (((res*res)%m)*2)%m;
        return ((res*res)%m);
    }

    // Intuition: For every valid pair for eg:
    // arr = [1, 2, 3] and k = 3, taking valid pair as 1,2 
    // we have to calculate how many times this valid subsequence will occur 
    // in total subsequence of arr. So every element other than 1,2 will have 2 choice
    // either to be with the valid pair or not be with so it's 2^(n - len(1,2))


    int m = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    // cnt represents len of (1,2)
    int solve(int i, ll cnt, ll sum, vector<int> &nums, int &k){
        // if sum becomes more than k then no use
        if(sum > k)
            return 0;

        if(sum == k)
            return power(nums.size() - cnt);

        if(i >= nums.size())
            return 0;

        if(dp[i][cnt][sum] != -1)
            return dp[i][cnt][sum];


        ll take = solve(i+1, cnt+1, sum + nums[i], nums, k);
        ll not_take = solve(i+1, cnt, sum, nums, k);

        return dp[i][cnt][sum] = (take + not_take)%m;
    }

    int sumOfPower(vector<int>& nums, int k) {
        dp.resize(100, vector<vector<int>>(110, vector<int>(110, -1)));
        return solve(0, 0, 0, nums, k);  
    }
};