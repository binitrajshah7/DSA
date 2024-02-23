class Solution {
public:
    // Intuition: DFS approach we keep on going deep and keep track of a particular path only
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create GRAPH
        // {node: [{neighbor_node, cost}]}
        unordered_map<int, vector<pair<int, int>>> graph;
        for(auto flight: flights)
            graph[flight[0]].push_back({flight[1], flight[2]});

        vector<int> cost(n, -1);
        cost[src] = 0;

        // here pq stores station and total cost to reach the station from our src {station, cost}
        queue<pair<int, int>> pq;
        pq.push({src, 0});

        while(!pq.empty()){
            int size = pq.size();
            
            for(int i=0; i<size; i++){
                auto node = pq.front();
                pq.pop();
                for(auto neighbor: graph[node.first]){
                    int price = node.second + neighbor.second;
                    if(cost[neighbor.first] == -1 || cost[neighbor.first] > price){
                        pq.push({neighbor.first, price});
                        cost[neighbor.first] = price;
                    }
                }
            }
            if(!k--)
                break;
        }

        return cost[dst];
    }
};