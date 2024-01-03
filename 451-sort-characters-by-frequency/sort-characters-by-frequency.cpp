class Solution {
public:
    // Intuition: Get freq map of all characters, push it to max heap sort with freq here
    // pop element one by one and add it to result string number of times it appears
    string frequencySort(string s) {
        unordered_map<char, int> mp;

        for(auto e: s)
            mp[e]++;

        priority_queue<pair<int, char>> pq;

        for(auto c: mp){
            char ch = c.first;
            int freq = c.second;
            pq.push({freq, ch});
        }

        string result = "";
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            for(int i=0; i<node.first; i++)
                result += node.second; 
        }   
        return result;
    }
};