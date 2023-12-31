class Solution {
public:
    // Optimal Approach: We use BFS here but with slight modification
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int r = matrix.size(), c = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[r-1][c-1];

        while(low<=high){
            int mid = (low+high)/2;
            // small_count stores how many elements are smaller than our mid
            int small_count = 0;
            // for every row 
            for(int i=0; i<r; i++){
                // upper bound gives iterator to element greater than mid
                small_count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if(small_count < k)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};