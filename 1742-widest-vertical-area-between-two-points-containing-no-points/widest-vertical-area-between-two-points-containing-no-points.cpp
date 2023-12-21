class Solution {
public:
    // Intuition find difference between consecutive points by sorting implies no points will be in between
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int result = INT_MIN;

        for(int i=1; i<points.size(); i++){
            result = max(result, points[i][0] - points[i-1][0]);
        }
        return result;
    }
};