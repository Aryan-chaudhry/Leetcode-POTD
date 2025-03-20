class Solution {
public:
    void dfs(int src, vector<vector<int>>&graph, vector<bool>&visited, vector<bool>&pathTracker, vector<int>store, vector<vector<int>>&path, int n){

        visited[src] = true;
        pathTracker[src] = true;
        store.push_back(src);

        if(src == n){
            path.push_back(store);
            pathTracker[src] = false;
            return;
        }

        for(auto nbr : graph[src]){
            if(!visited[nbr]){
                dfs(nbr, graph, visited, pathTracker, store, path, n);
            }
            else if(!pathTracker[nbr]){
                dfs(nbr, graph, visited, pathTracker, store, path, n);
            }
        }

        store.pop_back();
        pathTracker[src] = false;
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<bool>visited(n, false);
        vector<bool>pathTracker(n, false);
        vector<int>store;
        vector<vector<int>>path;

        int src = 0;

        dfs(src, graph, visited, pathTracker, store, path, n-1);
        return path;

    }
};