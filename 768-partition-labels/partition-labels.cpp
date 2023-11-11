class Solution {
public:

    // Intuition: Whenever we get a element we check last index of that character and mark it as possible answer for current group
    // Now we loop inside every element in that group and check whether last index of current element falls under same group or not
    // if not we increase the window/ group size

    vector<int> partitionLabels(string s) {
        // To optimise on time complexity here we pre-compute and keep last index of every element stored in our hashmap
        unordered_map<char, int> character_map;
        for (int i = 0; i < s.length(); i++)
            character_map[s[i]] = i;

        vector<int> result;
        for (int i = 0; i < s.length(); ){
            // start of a group
            int start_index = i;
            // potential end of a group
            int last_index = character_map[s[i]];
            // now traversing through every element in that particular group if last index of any element
            // goes outside the potential boundary then we increase the boundary
            for (int j = start_index + 1; j < last_index; j++)
                last_index = max(character_map[s[j]], last_index);

            // Result set will have boundary of every group
            result.push_back(last_index-start_index+1);
            // i will be set to start of new group
            i = last_index + 1;
        }
        return result;
    }
};