class Solution {
public:
    // Intuition: For every interval in our intervals we keep checking with our newInterval
    // 3 Condition may arrive doing so
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;

        for(auto interval: intervals){
            // if our current interval end is less than new interval start so we push our current interval
            if(interval[1] < newInterval[0])
                result.push_back(interval);

            // if our current interval starts after new interval so we push new Interval first and 
            // make current interval as new interval for next set of interation
            else if(interval[0] > newInterval[1]){
                result.push_back(newInterval);
                newInterval = interval;
            }

            // if overlapping then we take the maximum boundary from both ends
            else{
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }

        result.push_back(newInterval);
        return result;
    }
};