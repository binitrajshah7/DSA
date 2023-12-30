class Solution {
public:
    // Intuition: Just count the total freq of characters in all word
    // now check if every freq is divisible by n or not if not then false
    bool makeEqual(vector<string>& words) {
        int n = words.size();

        if(n==1)
            return true;

        vector<int> freq(26, 0);

        for(auto word: words){
            for (auto c: word){
                freq[c-'a']++;
            }
        }

        for(auto character_freq: freq)
            if(character_freq % n != 0)
                return false;

        return true;
    }
};