class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rowsize = grid.size();
        int colsize = grid[0].size();

        vector<vector<bool>>visited(rowsize, vector<bool>(colsize, false));
        int timer = 0;
        int minTimeToRot = 0;
        // make a queue
        queue<pair<pair<int,int>,int>>q; // --> {ri, ci}, time

        // i can traverse in 4 direction
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // maintain initail state
        // insert all rotten oranges in queue first

        for(int i=0; i<rowsize; i++){
            for(int j=0; j<colsize; j++){
                // rotten oranges --> 2
                if(!visited[i][j] && grid[i][j] ==  2){
                    q.push({{i,j},timer});
                    visited[i][j] = true;
                }
            }
        }

        // main logic

        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

            int ri = frontNode.first.first;
            int ci = frontNode.first.second;
            int time = frontNode.second;

            minTimeToRot = max(minTimeToRot, time);

            // ab jo oranges freh hai unhe sadao
            for(int i=0; i<4; i++){
                int nri = ri + dr[i];
                int nci = ci + dc[i];

                if(nri >= 0 && nri < rowsize && nci >= 0 && nci < colsize &&
                !visited[nri][nci] && grid[nri][nci] == 1){
                    q.push({{nri, nci},time+1});
                    visited[nri][nci] = true;
                    // mark it that is get roast --> to track that how many fresh oranges are left
                    grid[nri][nci] = 2;
                }
            }
        }

        // check how many fresh oranges are left
        int freshOrange = 0;

        for(int i=0; i<rowsize; i++){
            for(int j=0; j<colsize; j++){
                if(grid[i][j] == 1){
                    // fresh present
                    freshOrange++;
                }
            }
        }

        return freshOrange == 0 ? minTimeToRot : -1; 
    }
};