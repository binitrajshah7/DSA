class Solution {
public:
    
    void mark_neighbors(int i, int j, vector<vector<int>> &visited, vector<vector<char>> board){
        if (i < 0 || i >= visited.size() || j < 0 || j >= visited[0].size() || visited[i][j] == 1 || board[i][j] == 'X')
            return;
        visited[i][j] = 1;
        int del_row[] = {1, 0, -1, 0};
        int del_col[] = {0, -1, 0, 1};

        for(int k=0; k<4; k++){
            int n_row = i + del_row[k];
            int n_col = j + del_col[k];
            mark_neighbors(n_row, n_col, visited, board);
        }
    }

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        vector<pair<int, int>> boundary_zeros;
        for(int j=0; j<col; j++){
            if(board[0][j] == 'O')
                boundary_zeros.push_back({0, j});
            if(board[row-1][j] == 'O')
                boundary_zeros.push_back({row-1, j});
        }

        for(int i=0; i<row; i++){
            if(board[i][0] == 'O')
                boundary_zeros.push_back({i, 0});
            if(board[i][col-1] == 'O')
                boundary_zeros.push_back({i, col-1});
        }

        vector<vector<int>> visited(row, vector<int>(col, 0));
        for (auto element: boundary_zeros){
            int i = element.first;
            int j = element.second;
            if (visited[i][j] == 0)
                mark_neighbors(i, j, visited, board);
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == 'O' && !visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};