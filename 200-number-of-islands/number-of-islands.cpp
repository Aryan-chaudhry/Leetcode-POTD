class Solution {
public:
    void bfs(int r, int c, vector<vector<char>>&grid, vector<vector<bool>>&visited){
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;
        q.push({r,c});
        visited[r][c] = true;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newr = row + drow[i];
                int newc = col + dcol[i];

                if(newr >=0 && newr < m && newc >= 0 && newc < n && !visited[newr][newc] && grid[newr][newc] == '1'){
                    q.push({newr,newc});
                    visited[newr][newc] = true;
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        int count = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(i,j, grid, visited);
                    count++;
                }
            }
        }
        return count;
    }
};