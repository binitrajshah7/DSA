class Solution {
public:
    // Monotonic Stack + freq array + visited array
    string removeDuplicateLetters(string s) {
        
        // freq map
        vector<int> freq(26, 0);
        for(int i=0; i<s.length(); i++)
            freq[s[i] - 'a']++;

        // stores what values are already included in the stack
        vector<bool> visited(26, false);
        // keeps characters in lexicographically increasing order
        stack<char> st;

        for(int i=0; i<s.length(); i++){
            // if visited i.e already included in the stack before so no need to include so we decrease the freq and continue
            if(visited[s[i] - 'a']){
                freq[s[i] - 'a']--;
                continue;
            }

            // if top is greater than curr then we keep popping unless the top's freq is 0, if 0 then than element can't be found after
            // this point so we don't pop it instead push current after that after the while loop
            while(!st.empty() && st.top()>s[i] && freq[st.top() - 'a'] > 0){    
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            visited[s[i]-'a'] = true;
            freq[s[i] - 'a']--;
        }

        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};