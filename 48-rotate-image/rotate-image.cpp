class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        // Taking Transpose of matrix
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(j>i){
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
        // Now swapping columns from first to last
        for(int i=0; i<row; i++){
            for(int j=0; j<col/2; j++){
                swap(matrix[i][j], matrix[i][col-j-1]);
            }
        }
    }
};