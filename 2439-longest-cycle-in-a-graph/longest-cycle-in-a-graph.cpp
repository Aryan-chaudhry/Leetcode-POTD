class Solution {
public:
    void solve(int src, int parent, unordered_map<int,list<int>>&adj, unordered_map<int,bool>&visited, unordered_map<int,bool>&dfsTracker, unordered_map<int,int>&lengthTracker, int &longestCycle, int distance){
        visited[src] = true;
        dfsTracker[src] = true;
        lengthTracker[src] = distance;

        for(auto nbr : adj[src]){
            if(!visited[nbr]){
                solve(nbr, src, adj, visited, dfsTracker, lengthTracker, longestCycle, distance+1);
            }
            else if(visited[nbr] && dfsTracker[nbr]){
                longestCycle = max(longestCycle, lengthTracker[src]-lengthTracker[nbr]+1);
            }
        }
        dfsTracker[src] = false;
    }

    int longestCycle(vector<int>& edges) {
        unordered_map<int,list<int>>adj;

        for(int i=0; i<edges.size(); i++){
            adj[i].push_back(edges[i]);
        }

        unordered_map<int,bool>visited;
        unordered_map<int,bool>dfsTracker;
        unordered_map<int,int>lengthTracker;
        int longestCycle = -1;
        int parent = -1;
        int distance = 1;

        for(int src=0; src<edges.size(); src++){
            if(!visited[src]){
                solve(src, parent, adj, visited, dfsTracker, lengthTracker, longestCycle, distance);
            }
        }
        return longestCycle;
    }
};