class Solution {
public:
    // Since our i and j were going to -1 in our recursive call so we right shifted our index by 1 so base case is handled
    int longestCommonSubsequence(string text1, string text2) {
        int r = text1.length();
        int c = text2.length();
        vector<vector<int>> dp(r+1, vector<int>(c+1, 0));

        // Base Case if(i==0 || j==0 return 0;)
        for(int j=0; j<c; j++)
            dp[0][j] = 0;

        for(int i=0; i<r; i++)
            dp[i][0] = 0;

        // Write down changing parameters in Bottom up approach
        for(int i=1; i<=r; i++){
            for(int j=1; j<=c; j++){
                // copy the recurrence
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[r][c];
    }
};