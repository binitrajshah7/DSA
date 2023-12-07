class Solution {
public:
    // Intuition: If we have answer for a/b we plot it to graph like a--2.0-->b if a/b is 2 then b/a is 0.5
    // We plot our graph accordingly now to solve any equation we just keep going through the possible way 
    // and keep multiplying the weights that comes across in our dfs solution
    double dfs(string source, string destination, unordered_map<string, vector<pair<string, double>>> &graph, unordered_map<string, bool> &visited){
        if(source == destination)
            return 1.0;

        visited[source] = true;
        double val = 1.0;

        // for every neighbor node of source
        for (auto neighbor : graph[source]){
            // if it is not already visited
            if(visited.count(neighbor.first) == 0){
                // multiply the weight in our answer and call for dfs to take the next node
                val = neighbor.second * dfs(neighbor.first, destination, graph, visited);
                if(val > 0)
                    return val;
            }
        }

        // if not possible to reach the node from source return -1
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // GRAPH MODEL: (Node: [{neighbor_node, weight}])
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i=0; i<equations.size(); i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }

        // result array
        vector<double> result;
        for (int i=0; i<queries.size(); i++){
            // for every query we will have source and destination
            string source = queries[i][0];
            string destination = queries[i][1];
            
            // if any of the node is not present in graph then simply store -1 i.e equation can't be solved
            if(graph.count(source) == 0 || graph.count(destination) == 0)
                result.push_back(-1.0);

            // else we call the dfs and get the total weights encountered in the path
            else{
                unordered_map<string, bool> visited;
                double val = dfs(source, destination, graph, visited);
                result.push_back(val);
            }
        }
        return result;
    }
};