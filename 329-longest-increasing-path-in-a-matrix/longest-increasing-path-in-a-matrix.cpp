class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &visited){
        if(visited[i][j] != -1)
            return visited[i][j];
        int del_row[] = {0, 1, 0, -1};
        int del_col[] = {-1, 0, 1, 0};
        int length = 1;
        for (int k = 0; k < 4; k++)
        {
            int n_row = i + del_row[k];
            int n_col = j + del_col[k];
            if(n_row>=0 && n_row<matrix.size() && n_col>=0 && n_col<matrix[0].size() && matrix[n_row][n_col] > matrix[i][j]){
                length = max(length, 1+solve(n_row, n_col, matrix, visited));
            }
        }
        return visited[i][j] = length;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> visited(row, vector<int>(col, -1));
        int result = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(visited[i][j] == -1)
                    result = max(result, solve(i, j, matrix, visited));
            }
        }
        return result;
    }
};