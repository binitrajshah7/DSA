class Solution {
public:
    // Optimal Solution: Binary Search Approach
    // Find the closest element's index to x and traverse on both side with 2 pointers to get k closest element
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        int closest_to_target = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = closest_to_target - 1;
        int right = closest_to_target;

        while(k--){
            if(right>=n || (left>=0 && x-arr[left] <= arr[right]-x))
                left--;
            else
                right++;
        }
        // as left can be -1th index here right is exclusive so no check required
        return vector<int> (arr.begin()+left+1, arr.begin()+right);
    }
};