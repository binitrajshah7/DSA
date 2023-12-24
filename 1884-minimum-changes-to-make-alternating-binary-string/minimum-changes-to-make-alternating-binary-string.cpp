class Solution {
public:
    // Intuition: We consider our string to start from 0 and deviate at every position alternately
    // i.e in even index it should be 0 and at odd index it should be 1 if not so we increase our count
    int minOperations(string s) {
        int count = 0;
        int n = s.length();
        for(int i=0; i<n; i++){
            // even index and s[i] == 1 then we need to increase count
            if((i & 1) == 0 && s[i] == '1') count++;
            // odd index and s[i] == 0 then we need to increase the count
            if((i & 1) == 1 && s[i] == '0') count++; 
        }

        // here count represents deviation starting from 0 and n-count is deviation starting from 1
        // whichever way si minimum we take that way
        return min(count, n - count);
    }
};