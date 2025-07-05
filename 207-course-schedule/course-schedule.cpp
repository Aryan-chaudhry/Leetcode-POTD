class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adj;
        vector<int>ans;

        for(int i=0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        // lets find the indegree of each node
        unordered_map<int,int>indegree;

        for(int src=0; src<numCourses; src++){
            for(auto nbr : adj[src]){
                // edge src --> nbr
                indegree[nbr]++;
            }
        }

        queue<int>q;
        // push all nodes having indegree 0
        // maintain initail state
        for(int node=0; node<numCourses; node++){
            if(indegree[node] == 0){
                q.push(node);
            }
        }

        // main logic
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for(auto nbr : adj[frontNode]){
                // source node hat chuka hai to indeegree minus karo
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        // ab agar koi cycle nahi hoga toi course pure ho chuke honge
        return ans.size() == numCourses ? true : false;        
    }
};