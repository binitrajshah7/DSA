class Solution {
public:
    // Intuition: We always keep track of last index of last found invalid parenthesis 
    int longestValidParentheses(string s) {
        // stores opening braces to verify whether it is a valid parenthesis or not
        stack<char> character_stack;
        // stores last index of last found invalid parenthesis
        stack<int> index_stack;

        // we keep a dummy invalid pointer to -1 so if whole string is valid we subtrack our i with -1
        // eg: string: (()) so our last invalid was at -1 and i will be at 3 so, 3-(-1)
        index_stack.push(-1);
        int result = 0;
        for (int i=0;i<s.length(); i++){
            if (s[i] == ')'){
                if(!character_stack.empty()){
                    character_stack.pop();
                    index_stack.pop();
                    int last_index_of_invalid = index_stack.top();
                    // If the top of the stack is not -1 then we have found a valid pair and update our answer accordingly
                    result = max(result, i - last_index_of_invalid);
                }
                else
                    index_stack.push(i);
            }
            else{
                character_stack.push(s[i]);
                index_stack.push(i);
            }
        }
        return result;
    }
};