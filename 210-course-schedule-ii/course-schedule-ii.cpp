class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        // lets make adj list
        unordered_map<int,list<int>>adj;

        for(auto temp : prerequisites){
            adj[temp[0]].push_back(temp[1]);
        }

        // now find the indegree of each node
        unordered_map<int,int>indegree;

        for(int src=0; src<numCourses; src++){
            for(auto nbr : adj[src]){
                // edge --> src --> nbr
                indegree[nbr]++;
            }
        }

        // maintain a queue
        queue<int>q;

        // now inseret all node having endegree 0
        for(int node = 0; node<numCourses; node++){
            if(indegree[node] == 0){
                q.push(node);
            }
        }

        // main logic
        while(!q.empty()){
            int src = q.front();
            q.pop();

            // store ans
            ans.push_back(src);

            for(auto nbr : adj[src]){
                // src hat chuke hai to indegree subtract karo
                indegree[nbr]--;
                // jis bhi node ke indegree 0 ho gai use queue me insert karo
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
        // check karo course hue ya nahi
        reverse(ans.begin(), ans.end());
        if(ans.size() == numCourses) return ans;
        return {};
    }
};