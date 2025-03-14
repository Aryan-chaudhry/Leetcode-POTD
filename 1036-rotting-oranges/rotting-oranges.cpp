class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int,int>>q; // because of i,j th index orange
        int freshOranges = 0;

        // step 1  all the rotten oranges to the queue

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 2) q.push({i,j}); 
                else if(grid[i][j] == 1) freshOranges++;
            }
        }

        if(!freshOranges) return 0;

        // main logic
        int minutes = 0;
        vector<pair<int,int>>directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        // perform bfs
        while(!q.empty()){
            int size = q.size(); // rotten oranges --> level 1
            bool hasRottenNew = false;

            // processing current level / T / min
            for(int i=0; i<size; i++){
                auto curr = q.front();
                q.pop();

                for(auto dir : directions){
                    int newRow = curr.first + dir.first;
                    int newCol = curr.second + dir.second;
                    // check out of bounds

                    // if adjCell is a fresh Orange , so rot it
                    if(newRow >=0 && newRow < rows
                     && newCol >=0 && newCol < cols
                     && grid[newRow][newCol] == 1){
                        grid[newRow][newCol] = 2;
                        freshOranges--;
                        q.push({newRow, newCol}); // for next level
                        hasRottenNew = true;
                     }
                }           
            }
            if(hasRottenNew) minutes++;  
        }
    // step 3 checking
    if(freshOranges > 0) return -1;
    return minutes;
    }
};