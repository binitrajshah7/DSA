class Solution {
public:
    // Intuition: We keep pattern window and string window both of pattern size
    vector<int> findAnagrams(string s, string p) {
        // s_map and p_map will keep track of frequency of element in both windows
        unordered_map<char, int> s_map, p_map;
        // We will keep window of our pattern size as we need to find characters from our pattern
        for(int i=0; i<p.size(); i++){
            s_map[s[i]]++;
            p_map[p[i]]++;
        }

        vector<int> result;
        // if our s_map is equal to p_map i.e first window itself matches
        if(s_map == p_map)
            result.push_back(0);

        // left boundary of window
        int left = 0;
        for(int right=p.size(); right<s.size(); right++){
            // sliding window here adding right and removing left element
            s_map[s[right]]++;
            s_map[s[left]]--;
            // Note: If removed key frequency becomes 0 then we erase the key also
            if(s_map[s[left]] == 0)
                s_map.erase(s[left]);
            left++;
            // answer check
            if(s_map == p_map)
                result.push_back(left);
        }

        return result;
    }
};