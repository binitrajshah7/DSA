class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<long long>> grid(row, vector<long long> (col, 0));

        bool obstacle = false;
        for(int i=row-1; i>=0; i--){
            if(obstacleGrid[i][col-1] == 1){
                obstacle = true;
            }
            if(obstacle)
                grid[i][col-1] = 0;
            else
                grid[i][col-1] = 1;
        }

        obstacle = false;
        for(int j=col-1; j>=0; j--){
            if(obstacleGrid[row-1][j] == 1){
                obstacle = true;
            }
            if(obstacle)
                grid[row-1][j] = 0;
            else
                grid[row-1][j] = 1;
        }

        for(int i=row-2; i>=0; i--){
            for(int j=col-2; j>=0; j--){
                if(obstacleGrid[i][j] == 1)
                    grid[i][j] = 0;
                else{
                    grid[i][j] = grid[i][j+1] + grid[i+1][j];
                }
            }
        }

        return grid[0][0];
    }
};