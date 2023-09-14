class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string str: strs){
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            mp[sorted_str].push_back(str);
        }
        vector<vector<string>> result;
        for (auto pair: mp)
            result.push_back(pair.second);
        return result;
    }
};