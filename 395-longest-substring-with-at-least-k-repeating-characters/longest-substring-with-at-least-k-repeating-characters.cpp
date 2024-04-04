class Solution {
public:
    // Intuition: For a given string we keep a map of frequence now after that we 
    // linearly iterate through the string and check where the freq of element has freq < k
    // if found implies it is the confict zone we can't make our answer with the given char so
    // we split string into 2 halves before confict zone and after conflict zone and after conflict zone
    // and take max of both sides 
    int longestSubstring(string s, int k) {
        int n = s.length();
        if(k<=1)
            return n;
        if(n==0 || n<k)
            return 0;

        unordered_map<char, int> mp;
        for(auto e: s)
            mp[e]++;

        // index here gives the start of conflict zone
        int index = 0;
        while(index<n && mp[s[index]] >= k)
            index++;
        
        // if conflict not found then length of string
        if(index >= n-1)
            return index;

        // calling for first half
        int ls1 = longestSubstring(s.substr(0, index), k);     
        
        // skipping conflict zone
        while(index<n && mp[s[index]] < k)
            index++;

        // second half
        int ls2 = (index < n)? longestSubstring(s.substr(index), k): 0;
        return max(ls1, ls2);
    }
};