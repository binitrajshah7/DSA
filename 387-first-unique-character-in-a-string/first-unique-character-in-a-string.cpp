class Solution {
public:
    // Intuition: Maintain freq hash
    int firstUniqChar(string s) {
        int result = -1;
        unordered_map<char,int> mp;
        for(auto it: s)
            mp[it]++;

        for(int i=0; i<s.length(); i++)
            if(mp[s[i]] == 1)
                return i;
        return result;
    }
};