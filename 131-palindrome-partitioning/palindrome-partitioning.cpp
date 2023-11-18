class Solution {
public:
    // Intuition: We partition for every index possible in the string if the first half is palindrome then only we will call for our next
    // half to break it further else we will stop
    bool is_palindrome(string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }


    void solve(int index, string s, vector<string> &list, vector<vector<string>> &result){
        // we start from partitioning from 0 index whenever we reach our last partition i.e s.length() we add our list to our result and return
        if(index == s.length()){
            result.push_back(list);
            return;
        }
        // for every point we will partition
        for(int i=index; i<s.length(); i++){
            // if first half is palindrom then only partition further
            if(is_palindrome(s, index, i)){
                // we push current palidromic substring to list and call for next index to start from
                list.push_back(s.substr(index, i-index+1));
                solve(i+1, s, list, result);
                // backtrack to remove partition
                list.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<string>> result;
        vector<string> list;
        solve(0, s, list, result);
        return result;
    }
};