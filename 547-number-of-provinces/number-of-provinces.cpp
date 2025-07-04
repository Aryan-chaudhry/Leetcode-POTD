class Solution {
public:
    void bfs(int src, unordered_map<int,bool>&visited, vector<vector<int>>&isConnected){
        queue<int>q;

        // maintain initail state
        q.push(src);
        visited[src] = true;

        // main logic
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            for(int j=0; j<isConnected[frontNode].size(); j++){
                if(!visited[j] && isConnected[frontNode][j] == 1){
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // count the no of disconnected components
        int count = 0;

        unordered_map<int,bool>visited;
        for(int src=0; src<isConnected.size(); src++){
            if(!visited[src]){
                bfs(src, visited, isConnected);
                count++;
            }
        }
    return count;
    }
};