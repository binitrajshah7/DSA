class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq_s(26, 0);
        vector<int> freq_t(26, 0);

        for(int i=0; i<s.length(); i++){
            freq_s[s[i] - 'a']++;
            freq_t[t[i] - 'a']++;
        }

        int result = 0;
        for(int i=0; i<26; i++){
            if(freq_s[i] > freq_t[i])
                result += (freq_s[i] - freq_t[i]);
        }

        return result;
    }
};