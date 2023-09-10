class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Hint: At every index we will require left small and right small to that
        // i.e nothing but left boundary and right boundary
        int n = heights.size();

        // so we precompute them and store them in an array
        vector<int> left_small(n, INT_MIN);
        vector<int> right_small(n, INT_MIN);

        // for getting our left/right smaller element we will require stack
        // we will always keep element in increasing order in stack 
        stack<int> st1;
        for (int i = 0; i < n; i++){
            // whenever stack is empty that means our boundary is at first i.e at 0
            if(st1.empty()){
                left_small[i] = 0;
                st1.push(i);
            }
            else{
                // else we will pop all the element i.e greater than our current element from the stack
                while(!st1.empty() && heights[st1.top()] >= heights[i])
                    st1.pop();
                // if all element is popped out that implies boundary is at 0 and we keep current element
                // as the potential to be left_small for further element
                if(st1.empty())
                    left_small[i] = 0;
                // if stack is not empty that implies we found some element that is smaller than current element
                else
                    left_small[i] = st1.top() + 1;
                st1.push(i);
            }
        }
        // similarly we do for right small too but we traverse backwards
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
            int current_rectangle = heights[i] * (right_small[i] - left_small[i] + 1);
            result = max(result, current_rectangle);
        }
        return result;
    }
};