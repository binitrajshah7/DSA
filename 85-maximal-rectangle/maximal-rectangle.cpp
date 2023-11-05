class Solution {
public:
    int get_largest_rectangle_in_histogram(vector<int> heights){
        int n = heights.size();
        vector<int> left_small(n, INT_MIN);
        vector<int> right_small(n, INT_MIN);
        
        stack<int> st1;
        for(int i=0; i<n; i++){
            if(st1.empty())
                left_small[i] = 0;
            else{
                while(!st1.empty() && heights[i] <= heights[st1.top()])
                    st1.pop();
                if(st1.empty())
                    left_small[i] = 0;
                else
                    left_small[i] = st1.top() + 1;
            }
            st1.push(i);
        }

        stack<int> st2;
        for (int i = n-1; i >= 0; i--){
            if(st2.empty()){
                right_small[i] = n-1;
                st2.push(i);
            }
            else{
                while(!st2.empty() && heights[st2.top()] >= heights[i])
                    st2.pop();
                if(st2.empty())
                    right_small[i] = n-1;
                else
                    right_small[i] = st2.top() - 1;
                st2.push(i);
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++){
            int curr_result = (right_small[i] - left_small[i] + 1) * heights[i];
            result = max(result, curr_result);
        }
        return result;
    }

    // Intuition is same like finding largest rectangle in histogram 
    // for every row we calculate height for that row and get largest rectangle for that histogram row
    int maximalRectangle(vector<vector<char>>& matrix) {
        int result = 0;
        vector<int> heights(matrix[0].size(), 0);
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            result = max(result, get_largest_rectangle_in_histogram(heights));
        }
        return result;
    }
};