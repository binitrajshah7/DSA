class Solution {
public:
    bool isPalindrome(string &s, int left, int right){
        while(left<right) if(s[left++]!=s[right--]) return false;
        return true;
    }
    
    int minCut(string &s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        for(int ind = n-1;ind>=0;ind--){
            int mini = 1e9;
            for(int i = ind;i<n;i++){
                if(isPalindrome(s,ind,i)){
                    int cut = 1+dp[i+1];
                    mini = min(mini,cut);
                }
            }
            dp[ind] = mini;
        }
        return dp[0];
    }
};