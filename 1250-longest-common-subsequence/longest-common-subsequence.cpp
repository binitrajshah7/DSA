class Solution {
public:
    // Intuition: 
    // Brute Force: Generate all the subsequence [recursive or power set method] and check for every 
    // subsequence from text1 with subsequence of text2

    // Better Approach: We generate subsequence & keep on checking for the longest on the go
    // We traverse from back and check whether current index of t1 and t2 matches or not
    int solve(string &text1, int index1, string &text2, int index2, vector<vector<int>> &dp){
        if(index1 < 0 || index2 < 0)
            return 0;

        if(dp[index1][index2] != -1)
            return dp[index1][index2];

        // Condition 1: When index of both t1 and t2 matches then we move both pointers one behind [MATCH] 
        if(text1[index1] == text2[index2])
            return dp[index1][index2] = 1+solve(text1, index1-1, text2, index2-1, dp);

        // we move 1 index from t1 and call recursively and 1 index from t2 and call again [NOT MATCH]
        // we take maximum of of both recursive call
        return dp[index1][index2] = max(solve(text1, index1-1, text2, index2, dp), solve(text1, index1, text2, index2-1, dp)); 
    }

    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length();
        int l2 = text2.length();

        vector<vector<int>> dp(l1, vector<int>(l2, -1));
        return solve(text1, l1-1, text2, l2-1, dp);
    }
};