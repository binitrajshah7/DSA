class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();

        vector<int> dp(26, 0);
        int result = 0;

        for(int i=0; i<n; i++){
            int element = s[i] - 'a';
            // traverse to k left element in lexicographical order
            for(int j=element; j>=0 && j>=element-k; j--){
                if(element == j && dp[j] == 0){
                    dp[j] = 1;
                    result = max(result, dp[element]);
                    continue;
                }

                dp[element] = max(dp[j]+1, dp[element]);
            }

            // traverse to k right element in lexicographical order
            for(int j=element+1; j<26 && j<=element+k; j++){
                dp[element] = max(dp[j]+1, dp[element]);
            }

            result = max(result, dp[element]);
        }

        return result;
    }
};