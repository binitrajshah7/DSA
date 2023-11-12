class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(102, 0);
        int n = s.length();
        dp[n+1] = 1;
        dp[n] = 1;
        for(int index=n-1; index>=0; index--){
            int left=0, right=0;
            left = s[index]-'0';
            if(index < s.length()-1)
                right = left*10 + s[index+1] - '0'; 
            if(left > 0)    
                dp[index] += dp[index+1];
            if(left > 0 && right > 0 && right <= 26)
                dp[index] += dp[index+2];
        }
        return dp[0];    
    }    
};