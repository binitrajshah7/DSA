class Solution {
public:
    // Intuition: 
    int numBusesToDestination(vector<vector<int>>& routes, int source, int destination) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < routes.size(); i++){
            for (int j = 0; j < routes[i].size(); j++){
                mp[routes[i][j]].push_back(i);
            }
        }
        int min_buses = 0;

        queue<int> q;
        q.push(source);

        vector<int> visited(routes.size(), 0);
        while (!q.empty()){
            int size = q.size();
            
            while(size--){
                int stop = q.front();
                q.pop();

                if(stop == destination)
                    return min_buses;

                for (auto route : mp[stop]){
                    if(!visited[route]){
                        for (auto station : routes[route]){
                            q.push(station);
                        }
                        visited[route] = 1;
                    }
                }
            }
            min_buses++;
        }
        return -1;
    }
};