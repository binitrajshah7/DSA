#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    DisjointSet ds(7);

    ds.union_by_rank(1, 2);
    ds.union_by_rank(2, 3);
    ds.union_by_rank(4, 5);
    ds.union_by_rank(6, 7);
    ds.union_by_rank(5, 6);


    if(ds.find_ultimate_parent(3) == ds.find_ultimate_parent(7))
        cout << "Same Component" << endl;
    else
        cout << "Different component" << endl;

    // Adding edge from 3 to 7
    ds.union_by_rank(3, 7);
    if(ds.find_ultimate_parent(3) == ds.find_ultimate_parent(7))
        cout << "Same Component" << endl;
    else
        cout << "Different component" << endl;


    DisjointSet ds2(7);
    ds2.union_by_size(1, 2);
    ds2.union_by_size(2, 3);
    ds2.union_by_size(4, 5);
    ds2.union_by_size(6, 7);
    ds2.union_by_size(5, 6);


    if(ds2.find_ultimate_parent(3) == ds2.find_ultimate_parent(7))
        cout << "Same Component" << endl;
    else
        cout << "Different component" << endl;

    // Adding edge from 3 to 7
    ds2.union_by_size(3, 7);
    if(ds2.find_ultimate_parent(3) == ds2.find_ultimate_parent(7))
        cout << "Same Component" << endl;
    else
        cout << "Different component" << endl;

    return 0;
}
