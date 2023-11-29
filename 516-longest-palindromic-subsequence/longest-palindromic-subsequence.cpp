class Solution {
public:
    // Intuition: Same as Longest common subsequence we just have to reverse the string and find the LCS
    // as one of the string is reversed whatever subsequence matches it will be a palindrome
    int longest_common_subsequence(string s1, string s2) {
        int n = s1.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][n];
    }

    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return longest_common_subsequence(s1, s2);
    }
};