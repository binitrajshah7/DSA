class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // we need to find loop in a graph
        vector<int> adj[numCourses];
        vector<int> indegree(numCourses, 0);
        // first we make adjacency list out of given prerequisite it will be a directed graph
        // and count indegree of the element and store
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        // Now we do BFS in our graph and the points with indegree 0 will be our starting points
        queue<int> q;
        for(int i=0; i<numCourses; i++)
            if(indegree[i] == 0)
                q.push(i);

        // BFS
        int count = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            count++;
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        // if graph has no loop we will visit all the 
        return count == numCourses;
    }
};