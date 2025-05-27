class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,list<int>>adj;

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int>q;
        unordered_map<int,bool>visited;

        // maintain initial state

        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            if(frontNode == destination) return true;

            for(auto nbr : adj[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    return false;
    }
};