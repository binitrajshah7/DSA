class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // As we can move right and bottom only so from every boundary element of right and bottom
        // we will have only one unique path to travel in straight way to our goal
        for (int i = 0; i < m; i++)
            for (int j = 0; j<n; j++)
                if(i==m-1 || j==n-1)
                    dp[i][j] = 1;
        // for every index from m-2 and n-2 we will have total unique path of 
        // right + total unique path of bottom
        for (int i=m-2; i >= 0; i--)
            for (int j=n-2; j>=0; j--)
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        return dp[0][0];
    }
};