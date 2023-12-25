class Solution {
public:
    // Intuition: we take a frequency array of given string now we iterate total size of our string
    // for given instance we add the maximum frequency element in our result and for next instance we add
    // maximum frequency element other than the current element from our frequency map
    string reorganizeString(string s) {
        // frequency map
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++)
            mp[s[i]]++;

        // to fetch maximum frequency character at constant time we use hash map where {frequency, character} is stored
        priority_queue<pair<int, char>, vector<pair<int, char>>> pq;
        for(auto e: mp)
            pq.push({e.second, e.first});
        
        string result = "";
        // initialising prev as null whenever we need to exclude a element for next call we store it in prev
        pair<int, char> prev = {0, 'a'};

        // while both is not empty
        while(!pq.empty() || prev.first > 0){
            // no element remains in heap but there exist a element in prev that has more frequency and excluded type
            // implies we can't make adjacent characters different
            if (prev.first > 0 && pq.empty())
                return "";

            // taking most frequent element
            pair<int, char> node = pq.top();
            pq.pop();
            char c = node.second;
            int count = node.first;

            // adding to result
            result += c;
            // decreasing the frequency
            count--;
            // After pushing prev back into the max heap, prev is reset to {0, 'a'},
            // indicating that no character is currently excluded.
            if(prev.first > 0){
                pq.push(prev); 
                prev = {0, 'a'};
            }
            // if prev is null then we take current character as previous i.e needs to be excluded in next call
            if(count != 0)
                prev = {count, c};
        }
        return result;
    }
};