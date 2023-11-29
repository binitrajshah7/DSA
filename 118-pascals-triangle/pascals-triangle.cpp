class Solution {
public:
    // Intuition: To fill every level we will consider previous level 2 elements as mentioned
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for(int i=0; i<numRows; i++){
            // for every level number of column element will increase
            result[i].resize(i+1);
            // as first and last element is always 1
            result[i][0] = result[i][i] = 1;
            // for middle element considering from level above 
            for(int j=1; j<i; j++){
                result[i][j] = result[i-1][j] + result[i-1][j-1];
            }
        }
        return result;
    }
};