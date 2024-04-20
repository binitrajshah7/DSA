class Solution {
public:
    // Intuition: We always keep on removing most significant peak from the number
    // i.e 1432219 -> 132219 -> 13219 -> 1219
    string removeKdigits(string num, int k) {
        // To store the increasing elements and eliminate peak we take a stack here where it stores our number in increasing order
        stack<char> st;
        for(auto ch: num){
            // if current character is lesser than top of stack that implies previous element is a peak
            // so we keep popping all the peak elements previous to current character and decrease k
            while(!st.empty() && st.top()>ch && k>0){
                st.pop();
                k--;
            }

            // as 0 has no significance in-front of number we ignore case when stack is empty and ch is 0
            if(!st.empty() || ch != '0')
                st.push(ch);
        }

        string result = "";
        // edge case: when our number itself is in increasing order every element will be pushed to stack and k will still have value
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }

        if(st.empty())
            return "0";

        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};