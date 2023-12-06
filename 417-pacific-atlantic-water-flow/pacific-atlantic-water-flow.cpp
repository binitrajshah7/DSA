class Solution {
public:
    // Intuition: We start from our boundary and call DFS for all boundary from both the oceans
    // if some cell is reachable from both oceans then we take that intersection as our result
    void dfs(int i, int j, vector<vector<int>> &visited, int previous_height, vector<vector<int>> &heights){
        if(i<0 || i>=visited.size() || j<0 || j>= visited[0].size() || visited[i][j] || previous_height > heights[i][j])
            return;

        visited[i][j] = 1;

        dfs(i-1,  j, visited,  heights[i][j], heights);
        dfs(i,  j+1, visited,  heights[i][j], heights);
        dfs(i+1,  j, visited,  heights[i][j], heights);
        dfs(i,  j-1, visited,  heights[i][j], heights);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size(), col = heights[0].size();
        // stores all the cells reachable from pacific boundary
        vector<vector<int>> visited_pacific(row, vector<int> (col, 0));
        // stores all the cells reachable from atlantic boundary
        vector<vector<int>> visited_atlantic(row, vector<int> (col, 0));

        // marking for first and last row
        for (int j = 0; j < col; j++){
            dfs(0, j, visited_pacific, heights[0][j], heights);
            dfs(row - 1, j, visited_atlantic, heights[row - 1][j], heights);
        }

        // marking for first and last col
        for (int i = 0; i < row; i++){
            dfs(i, 0, visited_pacific, heights[i][0], heights);
            dfs(i, col-1, visited_atlantic, heights[i][col - 1], heights);
        }

        // taking intersection point as our result
        vector<vector<int>> result;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(visited_pacific[i][j] && visited_atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }
};