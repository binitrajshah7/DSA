class Solution {
public:
    // Intuition: We make partition at every index possible [FRONT PARITIONING]
    // And keep track of length and maximum element of each partition
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for(int index = n-1; index>=0; index--){
            int length=0, maxi = INT_MIN, max_sum = INT_MIN;
            for(int i=index; i<min(n, index+k); i++){
                length++;
                maxi = max(maxi, arr[i]);
                int sum = length * maxi + dp[i+1];
                max_sum = max(max_sum, sum);
            }
            dp[index] = max_sum;
        }

        return dp[0];
    }
};