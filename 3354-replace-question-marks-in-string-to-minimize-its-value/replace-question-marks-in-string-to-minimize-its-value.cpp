class Solution {
public:
    // Intuition: While replacing every '?' we can make decision on the basis that how many times 
    // a character has occured in the string despite of left or right as including max occured char
    // will increase cost of other same subsequent characters so we keep a freq map of characters and
    // min heap that will give us min freq character at every point
    string minimizeStringValue(string s) {
        int n = s.length();
        // freq map
        unordered_map<char, int> mp;
        
        for(auto e: s)
            mp[e]++;
        
        // min heap
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        for(char ch = 'a'; ch<='z'; ch++){
            pq.push({mp[ch], ch});
        }
        
        // as answer should be lexicographically sorted we take result string sort it
        // and place it in all the adjacent '?'
        vector<int> indices;
        string result = "";
        for(int i=0; i<n; i++){
            if(s[i] == '?'){
                // take minimum occured add it to answer & push back it to heap with increased
                // freq as we have used it in our answer
                pair<int, char> node = pq.top();
                pq.pop();
                
                result.push_back(node.second);
                mp[node.second]++;
                
                pq.push({mp[node.second], node.second});
                indices.push_back(i);
            }
            
        }
         
        
        cout << "result: " << result << endl;
        sort(result.begin(), result.end());
        for(int i=0; i<indices.size(); i++){
            s[indices[i]] = result[i];    
        }
        
        return s;
                
    }
};
