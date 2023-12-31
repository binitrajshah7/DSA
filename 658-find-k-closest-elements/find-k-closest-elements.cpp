class Solution {
public:
    // Brute force: create a max heap of size k push element with abs of difference and pop element with max distance
    // if heap size becomes greater than k elements
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;

        for(auto e: arr){
            int difference = abs(e-x);
            pq.push({difference, e});
        
            if(pq.size() > k)
                pq.pop();
        }

        // pop the k element from heap and append to result
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top().second);
            pq.pop();
        }
        // ans result is required in sorted order
        sort(result.begin(), result.end());
        return result;
    }
};