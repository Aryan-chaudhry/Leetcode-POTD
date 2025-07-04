class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int src, vector<int>&visited){
        visited[src] = true;

        for(int j=0; j<isConnected.size(); j++){
            if(isConnected[src][j] == 1 && !visited[j]){
                dfs(isConnected, j, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        vector<int>visited(isConnected.size(), false);

        for(int src=0; src<isConnected.size(); src++){
            if(!visited[src]){
                dfs(isConnected, src, visited);
                count++;
            }
        }
    return count;
    }
};