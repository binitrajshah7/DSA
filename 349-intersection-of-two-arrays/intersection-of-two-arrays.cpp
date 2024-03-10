class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;

        for(auto e: nums1)
            st.insert(e);

        set<int> result;
        for(auto e: nums2){
            if(st.find(e) != st.end()){
                result.insert(e);
            }
        }
        return vector<int> (result.begin(), result.end());
    }
};