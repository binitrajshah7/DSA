class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> mp;
        for(auto e: s)
            mp[e]++;

        priority_queue<pair<int, char>> pq;
        for(auto e: mp){
            pq.push({e.second, e.first});
        } 

        string result = "";
        while(!pq.empty()){
            auto e = pq.top();
            pq.pop();
            for(int i=0; i<e.first; i++){
                result += e.second;
            }
        }
        return result;
    }
};