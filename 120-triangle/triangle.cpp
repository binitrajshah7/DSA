class Solution {
public:
    // Intui2tion: Seems to go up to bottom but as it is a dp problem we go from bottom up
    // cause last step will always have answer and going up we store minimum for every cell considering
    // bottom 2 cells 
    int minimumTotal(vector<vector<int>>& triangle) {
        int minimum = 0;
        int curr_index = 0;
        for(int i=triangle.size()-2; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                triangle[i][j] = triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};