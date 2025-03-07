class Solution {
public:
    void dfs(vector<vector<char>>&grid, int srcx, int srcy){
        if(srcx < 0 || srcx >= grid.size() || srcy < 0 || srcy >= grid[0].size() || grid[srcx][srcy] == '0') return;

        // visited matlab me es node ma aa chuka hu vapis nahi aaunga
        grid[srcx][srcy] = '0';

        // go in all possible direction
        dfs(grid, srcx, srcy+1);
        dfs(grid, srcx, srcy-1);
        dfs(grid, srcx+1, srcy);
        dfs(grid, srcx-1, srcy);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};