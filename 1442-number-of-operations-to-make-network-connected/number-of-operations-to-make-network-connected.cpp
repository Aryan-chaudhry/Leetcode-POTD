class Solution {
public:
    int findParent(vector<int>&parent, int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent, parent[node]);
    }

    void unionSet(int u, int v, vector<int>&parent, vector<int>&rank){
        u = findParent(parent, u);
        v = findParent(parent, v);

        if(rank[u] < rank[v]){
            parent[u] = v;
            rank[v]++;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent(n);
        vector<int>rank(n, 0);
        int noOfEdges = 0;
        int nocc = 0;

        // initially all nodes are parent of them self
        for(int node = 0; node<n; node++){
            parent[node] = node;
        }


        for(auto connection : connections){
            int u = connection[0];
            int v = connection[1];

            u = findParent(parent, u);
            v = findParent(parent, v);

            if(u != v){
                // they are from different component just combine them
                unionSet(u,v,parent,rank);
            }
            else{
                noOfEdges++;
            }
        }

        for(int u=0; u<n; u++){
            if(parent[u] == u){
                nocc++;
            }
        }

        int ans = nocc-1;

        return noOfEdges >= ans ? ans : -1;
    }
};