class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in_degree(numCourses, 0);
        vector<int> adjacency_list[numCourses];

        // Getting indegree for every graph node and preparing adjacency list for every node
        for(int i=0; i<prerequisites.size(); i++){
            in_degree[prerequisites[i][0]]++;
            adjacency_list[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        // We will start with the node whose in_degree is 0 as there is no prerequisite to complete this course
        // hence we push it to our queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if(in_degree[i] == 0)
                q.push(i);

        // Result set
        vector<int> result;
        // BFS
        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);
            for (auto adj_element : adjacency_list[node]){
                // for every adjacent element of a graph found we decrease its indegree
                // if indegree is 0 then it can be completed so we push it to our queue
                if (--in_degree[adj_element] == 0)
                    q.push(adj_element);
            }
        }
        // if result.size() is not equal to numCourses that implies we can't complete all course
        return numCourses == result.size() ? result : vector<int>{};
    }
};