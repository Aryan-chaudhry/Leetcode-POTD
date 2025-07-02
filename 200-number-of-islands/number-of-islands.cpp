class Solution {
public:
    void bfs(vector<vector<char>>&grid, int r, int c, vector<vector<bool>>&visited){
        int rowSize = grid.size();
        int colSize = grid[0].size();
        
        queue<pair<int,int>>q;
        // lets maintain the direction

        int drow[4] = {-1, 0, 1, 0 };
        int dcol[4] = {0, 1, 0, -1};
        
        // maintain initail state
        q.push({r,c});
        visited[r][c] = true;

        // main logic
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

            int rindex = frontNode.first;
            int cindex = frontNode.second;

            for(int i=0; i<4; i++){
                int newr = rindex + drow[i];
                int newc = cindex + dcol[i];

                // if it is valid to move here just move
                if(newr >= 0 && newr < rowSize && newc >=0 
                   && newc < colSize && grid[newr][newc] == '1' && !visited[newr][newc]){
                    q.push({newr, newc});
                    visited[newr][newc] = true;
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // count the number of disconnected components
        int noOfIslands = 0;
        
        int totalRow = grid.size();
        int totalCol = grid[0].size();

        // making visited vector
        vector<vector<bool>>visited(totalRow, vector<bool>(totalCol));

        for(int i=0; i<totalRow; i++){
            for(int j=0; j<totalCol; j++){
                if(grid[i][j] == '1' && visited[i][j] == false){
                    int src = grid[i][j];
                    bfs(grid, i, j, visited);
                    noOfIslands++;
                }
            }
        }
        return noOfIslands;
    }
};