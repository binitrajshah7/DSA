class Solution {
public:
     int actualCounts[26],countsTillNow[26],ans = 0;
     void solve(int ind,vector<string> &words,vector<int> &score){
        //base case
        if(ind==words.size()){
            int currScore = 0;
            //calculating the score of letters included in our current solution if they are less than the total count given to us originally

            //if any of the letter will exceed it we will simply return our function from there
            for(int i=0 ; i<26;i++){
                if(countsTillNow[i]>actualCounts[i]) return;
                currScore += score[i]*countsTillNow[i];
            }

            //updating the answer
            ans = max(ans,currScore);
            return;
        }
        //moving forward without considering the word as part of our solution
        solve(ind+1,words,score);

        //taking the word as part of our solution, hence adding the counts of letters of the words
        for(auto letter : words[ind]) countsTillNow[letter-'a']++;
        solve(ind + 1, words, score);

        //backtracking by removing the counts of letters of word
        for (auto letter : words[ind]) countsTillNow[letter - 'a']--;
     }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        //storing the counts of letters
        for(auto letter : letters) actualCounts[letter-'a']++;
        //recursive calling 
        solve(0,words,score);
        return ans;
    }
};