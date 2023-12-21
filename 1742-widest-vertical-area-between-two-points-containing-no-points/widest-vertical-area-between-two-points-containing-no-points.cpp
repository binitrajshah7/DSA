class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        // stores unique x co-ordinates 
        set<int> uniqueX; 
        for (const auto& point : points) {
            uniqueX.insert(point[0]); 
        }
        
        int maxDifference = 0;
        int previousX = INT_MIN;
        
        // for every x coordinate
        for (int x : uniqueX) {
            if (previousX != INT_MIN) {
                // subtracting from previous occurence of x to get width
                maxDifference = max(maxDifference, x - previousX); 
            }
            previousX = x;
        }
        
        return maxDifference;
    }
};