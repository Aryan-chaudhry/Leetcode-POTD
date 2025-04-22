class Solution {
public:
    void DFS(vector<vector<int>>& isConnected, vector<int>&visited, int src){
       visited[src] = true;

       for(int nbr=0; nbr<isConnected.size(); nbr++){
            if(isConnected[src][nbr] && !visited[nbr]){
                DFS(isConnected, visited, nbr);
            }
       }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int>visited(V,false);
        int count = 0;

        for(int src=0; src<V; src++){
            if(!visited[src]){
                DFS(isConnected, visited, src);
                count++;
            }
        }
    return count;
    }
};