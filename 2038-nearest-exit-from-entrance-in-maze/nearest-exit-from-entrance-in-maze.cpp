class Solution {
public:
    bool isExit(int &r, int &c, int &m, int &n){
        return (r == 0 || r == m-1 || c == 0 || c == n-1);
    }

    bool isSafeToTravel(int r, int c, vector<vector<char>>& maze, int &m, int &n, vector<vector<bool>>&visited){
       
        if(r >= 0 && r < m && c >=0 && c < n){
            if(maze[r][c] == '.' && visited[r][c] == false){
                return true;
            }
        }
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue< pair< pair<int,int>, int>>q; // {{row,col}, nearest_exit}
        vector<vector<bool>>visited(m, vector<bool>(n,false));

        // lets fetch source coordinate
        int srcx = entrance[0];
        int srcy = entrance[1];

        // i can move in 4 direction
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        // maintain initial state
        visited[srcx][srcy] = true;
        q.push({{srcx,srcy},0});

        // main logic
        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();

            int x = frontNode.first.first;
            int y = frontNode.first.second;
            int NearestExit = frontNode.second;

            if(isExit(x,y,m,n) && !(x == srcx && y == srcy)) return NearestExit;

            // lets Move
            for(int i=0; i<4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(isSafeToTravel(newx,newy,maze,m,n, visited)){
                    visited[newx][newy] = true;
                    q.push({{newx,newy},NearestExit+1});
                }
            }
        }
    return -1;
    }
};