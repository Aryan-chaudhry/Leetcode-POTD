class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>>adj;

        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        queue<int>q;
        unordered_map<int,int>indegree;
        vector<int>topo;

        // calculate indegree of each node
        for(int src=0; src<numCourses; src++){
            for(auto nbr: adj[src]){
                indegree[nbr]++;
            }
        }

        // maintain initial state
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // main logic
        while(!q.empty()){
            int frontNode = q.front();
            topo.push_back(frontNode);
            q.pop();

            for(auto nbr : adj[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        if(topo.size() == numCourses) return true;
        return false;
    }
};