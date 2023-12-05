class Solution {
public:
    // Intuition: Sliding Window Technique

    // gives count of most frequent character in a window
    int get_max_count(unordered_map<char, int> mp){
        int count = 0;
        for(auto it: mp)
            count = max(count, it.second);
        return count;
    }

    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int n = s.length();

        int left=0; int right=0;
        int result = 0;

        while(right<n){
            // Adding right element in our window
            mp[s[right]]++;

            // If window_length - count > k implies it's not valid window we have to exchange more than k characters
            // so we shrink the window from left and decrease the character frequency too
            while(right-left+1-get_max_count(mp) > k){
                mp[s[left]]--;
                left++;
            }
            // if valid we update result
            result = max(result, right-left+1);
            // and increase our window
            right++;
        }
        return result;
    }
};