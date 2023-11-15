class Solution {
public:
    // Brute Force: Maintain a max heap of size k push all elements from matrix whenever heap size is greater than k then pop the element
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        for(int i=0; i<matrix.size(); i++)
            for(int j=0; j<matrix[0].size(); j++){
                pq.push(matrix[i][j]);
                if(pq.size() > k)
                    pq.pop();
            }
        return pq.top();
    }
};