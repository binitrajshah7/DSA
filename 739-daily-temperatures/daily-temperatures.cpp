class Solution {
public:
    // Intuition: At every i traversing from back we make sure that our stack stores increasing numbers while popping elements
    // from stack so when we are at point i we make sure every element in stack is in increasing sequence from top to down
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> st;
        vector<int> result(n, 0);
        for(int i=n-1; i>=0; i--){
            // we pop out all elements from stack which is less than current element as it can't be result for our further temperatures traversing back
            while(!st.empty() && st.top().first <= temperatures[i])
                st.pop();
            if(st.empty())
                result[i] = 0;
            else
                result[i] = st.top().second - i;
            st.push({temperatures[i], i});
        }
        return result;      
    }
};