class Solution {
public:
    // Intuition: A graph can atmost have 2 MHTs. For eg. if we burn a graph from its leaf node at once i.e BFS
    // The last level can have either 1/2 node it is our answer
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};

        vector<vector<int>> adj_list(n);
        vector<int> in_degree(n, 0);

        // Making adjacency list and keeping count of indegree
        for(int i=0; i<edges.size(); i++){
            adj_list[edges[i][0]].push_back(edges[i][1]);
            adj_list[edges[i][1]].push_back(edges[i][0]);
            in_degree[edges[i][0]]++;
            in_degree[edges[i][1]]++;
        }

        // pushing all the nodes having indegree = 1 in our queue i.e leaf node for further BFS
        queue<int> q;
        for(int i=0; i<n; i++){
            if(in_degree[i]==1)
                q.push(i);
        }

        vector<int> result;
        while(!q.empty()){
            int s = q.size();
            // As we need only the last level
            result.clear();
            
            // We will pop every node from the queue and decrement in_degree of its neighbor edges 
            for(int i=0; i<s; i++){
                int node = q.front();
                q.pop();
                result.push_back(node);
                
                for(int neighbour: adj_list[node])
                    // if neighbor edges becomes leaf node then we push it to queeu
                    if(--in_degree[neighbour] == 1)
                        q.push(neighbour);
            }
        }
        return result;
    }
};