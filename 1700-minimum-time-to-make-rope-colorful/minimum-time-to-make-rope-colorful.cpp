class Solution {
public:
    // Intuition: While iterating in our rope whenever we get a multiple same characters we start our 
    // window from the same place and iterate to next different element for current window we store
    // maximum cost balloons and total cost of window size so that we keep maximum cost balloons and remove others
    int minCost(string colors, vector<int>& neededTime) {
        int left = 0, right = 0;
        int n = colors.size();
        int min_time = 0;

        while(left<n && right<n){
            // stores max cost balloon for current window and total cost of window size
            int curr_max = INT_MIN, curr_total = 0;

            // Window
            while(colors[left] == colors[right]){
                curr_max = max(curr_max, neededTime[right]);
                curr_total += neededTime[right];
                right++;
            }

            // starting new window again
            left = right;
            // excluding max cost and removing all other balloons
            min_time += curr_total-curr_max;
        }
        return min_time;
    }
};