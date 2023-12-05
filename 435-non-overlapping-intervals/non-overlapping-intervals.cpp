class Solution {
public:
    // We go through the greedy approach here
    // When we iterate in a sorted intervals 2 Condition might arrive either it is
    // overlapping or not overlapping if not overlapping then we take new End time of current interval
    // if overlapping then we take whatever is minimum end time of the both intervals 

    // as taking minimum end time might help to get less overlapping condition further
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int result = 0;
        int previous_end = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            // if previous_end == current_start then it's not a interval so <=
            if(previous_end <= intervals[i][0])
                previous_end = intervals[i][1];

            else{
                result++;
                previous_end = min(previous_end, intervals[i][1]);
            } 
        }
        return result;
    }
};