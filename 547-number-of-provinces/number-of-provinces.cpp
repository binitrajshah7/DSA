class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj_list, vector<int> &visited){
        visited[node] = 1;

        for(auto it: adj_list[node]){
            if(!visited[it]){
                dfs(it, adj_list, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj_list(V);

        for(int i=0; i<V; i++){
            for(int j=0; j<isConnected[i].size(); j++){
                if(isConnected[i][j] == 1 and i!=j){
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }

            }
        }

        int no_of_island = 0;
        vector<int> visited(V, 0);

        for(int i=0; i<V; i++){
            if(!visited[i]){
                no_of_island++;
                dfs(i, adj_list, visited);
            }
        }
        return no_of_island;
    }
};