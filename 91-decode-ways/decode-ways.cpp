class Solution {
public:
    // Intuition: We will always have 2 options either select one character and get number of ways for next set of characters
    // or consider 2 character at once and get number of ways from next set
    int solve(int index, string &s, vector<int> &dp){
        // Implies we traversed whole string so we return 1
        if(index >= s.length())
            return 1;

        if(dp[index] != -1)
            return dp[index];
            
        int result=0, left=0, right=0;
        left = s[index]-'0';
        if(index < s.length()-1)
            right = left*10 + s[index+1] - '0';
        // so we recursively call for both sides left subtree where we consider 1 character should be > 0  
        if(left > 0)    
            result += solve(index+1, s, dp);
        // Considering 2 characters in right subtree check should be first should not be '0' for case '06'
        // and should be in between range of 0 to 26
        if(left > 0 && right > 0 && right <= 26)
            result += solve(index+2, s, dp);

        // result will be sum from both sides
        return dp[index] = result;
    }

    int numDecodings(string s) {
        // As string length can be up to 100 chars long from constraints    
        vector<int> dp(101, -1);
        return solve(0, s, dp);    
    }    
};