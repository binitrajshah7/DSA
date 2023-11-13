class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        bool row = false, col = false;

        // Checking first row and first col has 0 or not
        for(int i=0; i<r; i++) if(matrix[i][0] == 0) col = true;
        for(int j=0; j<c; j++) if(matrix[0][j] == 0) row = true;

        // If we find 0 from 1,1 to row-1, m-1 we set its boudary to 0 for future reference
        for(int i=1; i<r; i++)
            for(int j=1; j<c; j++)
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }

        // marking all rows 0 from boundary check
        for(int i=1; i<r; i++)
            if(matrix[i][0] == 0)
                for(int j=0; j<c; j++)
                    matrix[i][j] = 0;

        // marking all cols 0 from boundary check
        for(int j=1; j<c; j++)
            if(matrix[0][j] == 0)
                for(int i=0; i<r; i++)
                    matrix[i][j] = 0;

        // Setting first row and first col as 0 if 0 was present in row or column at first
        if (row)  for (int j = 0; j < c; j++)     matrix[0][j] = 0;
        if (col) for (int i = 0; i < r; i++)     matrix[i][0] = 0;
    }
};