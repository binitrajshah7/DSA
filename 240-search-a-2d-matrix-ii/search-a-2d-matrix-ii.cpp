class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        int i = row-1, j= 0;
        while(i>=0 && j<col){
            if(matrix[i][j] == target)
                return true;
            else if(target < matrix[i][j])
                i--;
            else
                j++;
        }
        return false;
    }
};