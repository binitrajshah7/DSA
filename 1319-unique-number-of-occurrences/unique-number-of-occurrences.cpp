class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]]++;
        // declare a set
        unordered_set<int> s;
        // iterate over the map, and if we find any duplicate frequency then return false
        for(auto x : mp){
            // if duplicate frequency found
            if(s.count(x.second))
                return false;
            // insert the frequency into set   
            s.insert(x.second);
        }
        return true;
    }
};