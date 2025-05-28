class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, list<int>>adj;
        unordered_map<int,int>indegree;

        for(int src=0; src<graph.size(); src++){
            // original
            // src --> nbr

            // reverse
            // nbr --> src
            for(auto nbr : graph[src]){
                adj[nbr].push_back(src);
                indegree[src]++;
            }
            
        }

        queue<int>q;
        vector<int>safeState;

        for(int i=0; i<graph.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int Node = q.front();
            q.pop();
            safeState.push_back(Node);

            for(auto nbr : adj[Node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        sort(safeState.begin(), safeState.end());
        return safeState;
    }
};