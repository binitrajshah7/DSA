class Solution {
public:

    // Intuition: We have to find the minimum failing path from our first row
    // so we recursively go to last row as failing path of last row will be the element
    // itself and we go upwards in recursion after that so we go to all the row element below
    // current call excluding the column which we are in and take the minimum
    int solve(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp){
        
        int n = grid.size();
        // last row element is itself the failing path sum
        if (row == n-1)
            return grid[row][col];

        if(row == n)
            return 0;

        if(dp[row][col] != -1)
            return dp[row][col];

        int result = INT_MAX;
        for(int i=0; i<n; i++){
            // exclude current column element in below row
            if(i != col)
                result = min(result, solve(grid, row+1, i, dp));
        }

        // we have to add the current element and minimum failing from below row and return
        return dp[row][col]=result+grid[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(205, vector<int>(205, -1));
        int result = INT_MAX;
        // call for every first row element
        for(int i=0; i<grid.size(); i++){
            result = min(result, solve(grid, 0, i, dp));
        }
        return result;
    }
};