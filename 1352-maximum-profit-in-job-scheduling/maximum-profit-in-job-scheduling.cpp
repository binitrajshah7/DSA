class Solution {
public:
    // binary search to get next non overlapping interval i.e start_time of next job should be >= curr_job_end
    int get_next_index(vector<vector<int>> &intervals, int start, int curr_job_end){
        int n = intervals.size();
        int end = n-1;
        int result = n;
        while(start <= end){

            int mid = (start + end)/2;

            if(intervals[mid][0] >= curr_job_end){
                result = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return result;

    }

    int solve(int index, vector<vector<int>> &intervals, vector<int> &dp){
        if (index >= intervals.size())
            return 0;

        if(dp[index] != -1)
            return dp[index];

        // if not_pick then simply move to next index
        int not_pick = solve(index+1, intervals, dp);

        // if we pick then we have to get the next non conflicted interval after the end of current interval
        // as our intervals in sorted we do a binary search to get next non overlapping interval starting from index+1
        int next_pointer = get_next_index(intervals, index+1, intervals[index][1]);
        int pick = intervals[index][2] + solve(next_pointer, intervals, dp);

        // max of both ways
        return dp[index] = max(pick, not_pick);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        // intervals to profit map
        vector<vector<int>> intervals;
        for(int i=0; i<startTime.size(); i++)
            intervals.push_back({startTime[i], endTime[i], profit[i]});

        // sort on the basis of start time
        sort(intervals.begin(), intervals.end());

        vector<int> dp(intervals.size()+1, -1);
        return solve(0, intervals, dp);
    }
};