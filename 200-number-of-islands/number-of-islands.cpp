class Solution {
public:
    void mark_neighbour_visited(vector<vector<char>>& grid, vector<vector<bool>> &visited, int n, int m, int i, int j){
        int row[] = { -1, 0, 1, 0 };
        int col[] = { 0, 1, 0, -1 };
        visited[i][j] = true;
        for (int k = 0; k < 4; k++){
            int delRow = i + row[k];
            int delCol = j + col[k];
            if(delRow >=0 && delRow < n && delCol >= 0 && delCol < m && grid[delRow][delCol] == '1' && !visited[delRow][delCol])
                mark_neighbour_visited(grid, visited, n, m, delRow, delCol);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int result = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    result++;
                    mark_neighbour_visited(grid, visited, n, m, i, j);
                }
            }
        }
        return result;
    }
};