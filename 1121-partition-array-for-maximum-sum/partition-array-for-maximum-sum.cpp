class Solution {
public:
    int solve(vector<int>& arr, int k, int index, int n, vector<int> &dp){
        if(index == n)
            return 0;

        if(dp[index] != -1)
            return dp[index];

        int length=0, maxi = INT_MIN, max_sum = INT_MIN;
        for(int i=index; i<min(n, index+k); i++){
            length++;
            maxi = max(maxi, arr[i]);
            int sum = length * maxi + solve(arr, k, i+1, n, dp);
            max_sum = max(max_sum, sum);
        }
        return dp[index] = max_sum;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, k, 0, n, dp);
    }
};