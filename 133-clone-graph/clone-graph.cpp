/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    // Intuition: We keep a map of old to new node for given node we make a clone and call for its neighbors
    // if neighbor node is already in map that implies we have made the cloned node already so we simply push it to node's neigbor

    // else we call the dfs recursively to get the cloned node and push it to currents neighbors
    Node *dfs(Node* node, unordered_map <Node*, Node*> &mp){
        vector<Node*> neighbor;
        Node* clone = new Node(node->val);

        mp[node] = clone;
        for(auto neighbor_node: node->neighbors){
            if(mp.find(neighbor_node)!=mp.end())
                neighbor.push_back(mp[neighbor_node]);
            else
                neighbor.push_back(dfs(neighbor_node, mp));
        } 
        clone->neighbors = neighbor;  
        return clone;
    }

    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return NULL;

        if(node->neighbors.size() == 0){
            Node* clone = new Node(node->val);
            return clone;
        }

        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);

    }
};