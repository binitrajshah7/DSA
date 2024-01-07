class DisjointSet{
    vector<int> rank, parent, size;

public:
    // Initialisation 
    // n -> Number of graph nodes
    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        // ultimate parent of every node is node itself so every node is component in itself
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    // As we are finding ultimate parent here we also do a path compression here
    // whenever we get answer for a node we just assign same to all the childrens 
    // so ultimate parent of all the childrens in one component will be same
    int find_ultimate_parent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = find_ultimate_parent(parent[node]);
    }

    void union_by_rank(int u, int v){
        
        // ulp_u -> ultimate parent of u
        int ulp_u = find_ultimate_parent(u);
        int ulp_v = find_ultimate_parent(v);

        // Belongs to the same component
        if(ulp_u == ulp_v)
            return;

        // Don't belong to same component
        // ulp_u is lower rank than ulp_v then we attach u to v
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }

        // if rank of ulp_u is greater than ulp_v then we attach v to u
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }

        // if rank are same then anyone can be attached to other but the rank of the node to which
        // node is attached will increase
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // same as union by rank only difference is we consider graph size to make decision what should be attached to what
    // small size graph will get attached to greater size graph component and size of smaller graph will be added to larger
    void union_by_size(int u, int v){
        // ulp_u -> ultimate parent of u
        int ulp_u = find_ultimate_parent(u);
        int ulp_v = find_ultimate_parent(v);

        if(ulp_u == ulp_v)
            return;

        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        // create a disjoint set of n graph node components
        DisjointSet ds(n+1);

        // mail_to_node will store mail to graph node [(johnsmith@mail.com, 0), (johnnybravo@mail.com, 3)]
        unordered_map<string, int> mail_to_node;
        for(int i=0; i<n; i++){
            // as first contains name we don't consider it as of now
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                
                // if mail not found in map then simply insert it with node position
                if(mail_to_node.find(mail) == mail_to_node.end()){
                    mail_to_node[mail] = i;
                }
                // if already found implies we have to make union of the current node and make same parent
                else{
                    ds.union_by_size(i, mail_to_node[mail]);
                }
            }
        }

        // merged_mail stores all the mails with the same ultimate parent at a place
        // 0 -> johnsmith@mail.com, john_newyork@mail.com, john00@mail.com
        vector<string> merged_mail[n];
        for(auto it: mail_to_node){
            string mail = it.first;
            int node = ds.find_ultimate_parent(it.second);
            merged_mail[node].push_back(mail);
        }

        // After merge we simply go through every index and sort the merged_mail vector value and store in result
        vector<vector<string>> result;
        for(int i=0; i<n; i++){
            // some index can have empty mails after merge so we simply skip this same as all the mails
            // of this index would have been added to other graph component
            if (merged_mail[i].size() == 0)
                continue;
            
            // sort
            sort(merged_mail[i].begin(), merged_mail[i].end());
            vector<string> temp;
            // add name to the answer vector first
            temp.push_back(accounts[i][0]);

            // add sorted mail of every person/node
            for(auto mail: merged_mail[i])
                temp.push_back(mail);
            // push temp to result
            result.push_back(temp);
        }

        return result;
    }
};