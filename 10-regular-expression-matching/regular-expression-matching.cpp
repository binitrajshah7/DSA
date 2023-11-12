class Solution {
public:

    bool dfs(string &s, int i, string &p, int j, vector<vector<int>> &dp){
        if(dp[i][j] != -1)
            return dp[i][j];
        if(i>=s.length() && j>=p.length())
            return dp[i][j] = true;
        if(j>=p.length())
            return dp[i][j] = false;
        // Intuition: Case 1: When we match s[i] with p[j] or p[j] == '.' i.e can match with any string then further 2 cases can arrive
        bool match = false;
        if(i<s.length())
            match = (s[i] == p[j]) || (p[j] == '.');
        // Case 1.1: We can have * after jth element in pattern or not which leads to 2 more scenario
        if(j<p.length() && p[j+1] == '*'){
            // not considering start implies we take empty string so we simply jump 2 steps in pattern
            bool not_considering_star = dfs(s, i, p, j+2, dp);
            // To consider * to generate possible answer jth should match with ith element that we determine from match if it matches 
            // we simply move i forward  keeping j at same postion as * can make infinite occurence of character behind it
            bool considering_star = (match && dfs(s, i+1, p, j, dp));
            return dp[i][j] = not_considering_star || considering_star; 
        }

        // If we don't get * in p[j+1] then we simply check if its a perfect match or not if true we move both i and j pointers forward
        if(match)
            return dp[i][j] = dfs(s, i+1, p, j+1, dp);
        // if not we return false from here
        return  dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int sl = s.length();
        int pl = p.length();
        vector<vector<int>> dp(sl+1, vector<int>(pl+1, -1));
        return dfs(s, 0, p, 0, dp); 
    }
};