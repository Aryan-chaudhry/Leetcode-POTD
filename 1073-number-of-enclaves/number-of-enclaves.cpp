class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>&grid, vector<vector<bool>>&visited, int drow[], int dcol[]){
        visited[r][c] = true;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<4; i++){
            int newr = r + drow[i];
            int newc = c + dcol[i];

            if(newr >= 0 && newr < m && newc >= 0 && newc < n && !visited[newr][newc] && grid[newr][newc] == 1){
                dfs(newr, newc, grid, visited, drow, dcol);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int col=0; col<n; col++){
            if(!visited[0][col] && grid[0][col] == 1){
                dfs(0, col, grid, visited, drow, dcol);
            }
            if(!visited[m-1][col] && grid[m-1][col] == 1){
                dfs(m-1, col, grid, visited, drow, dcol);
            }
        }

        for(int row=0; row<m; row++){
            if(!visited[row][0] && grid[row][0] == 1){
                dfs(row, 0, grid, visited, drow, dcol);
            }
            if(!visited[row][n-1] && grid[row][n-1] == 1){
                dfs(row, n-1, grid, visited, drow, dcol);
            }
        }

        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};