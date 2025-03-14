class Solution {
public:
    void dfs(int src, vector<vector<int>>& isConnected, vector<bool>&visited){
        visited[src] = true;

        for(int j=0; j<isConnected.size(); j++){
            if(isConnected[src][j] && !visited[j]){
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size(), false);
        int provinves = 0;

        for(int i=0; i<isConnected.size(); i++){
            if(!visited[i]){
                dfs(i, isConnected, visited);
                provinves++;
            }
        }
        return provinves;
    }
};