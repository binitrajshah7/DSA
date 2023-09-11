class Solution {
public:
    bool check_exist(vector<vector<char>>& board, string word, int index, int i, int j, vector<vector<int>> &visited, int row, int col){
        // if our current index reaches last of word's length then we found our pattern
        if (index == word.length())
            return true;
        if (i<0 || i>=row || j<0 || j>=col || visited[i][j] || board[i][j] != word[index])
            return false;
        bool temp = false;
        // marking as visited as i, j is visited now and it has matched to index character of word
        visited[i][j] = 1;
        int delRow[4] = {0, 1, 0, -1};
        int delCol[4] = {1, 0, -1, 0};
        // now we will go to all the possible path from i, j and if any path gives us the pattern we will return true
        // so iterating through every path and calling recursively forward
        for (int k=0; k<4; k++)
            temp = temp || check_exist(board, word, index + 1, i + delRow[k], j + delCol[k], visited, row, col);
        // if we didn't find our pattern from all 4 paths then we mark current i, j as non visited for further to consider
        // from other paths starting from other variables
        visited[i][j] = 0;
        return temp;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> visited(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if(board[i][j] == word[0])
                    if(check_exist(board, word, 0, i, j, visited, row, col))
                        return true;
        return false;
    }
};