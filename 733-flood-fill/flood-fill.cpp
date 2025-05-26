class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        queue< pair< pair<int,int>, int>>q;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        
        // maintiaN initial state
        int c = image[sr][sc];

        q.push({{sr, sc}, c});
        visited[sr][sc] = true;
        image[sr][sc] = color;

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int clr = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newr = r + drow[i];
                int newc = c + dcol[i];

                if(newr >= 0 && newr < m && newc >= 0 && newc < n && !visited[newr][newc] && image[newr][newc] == clr){
                    clr = image[newr][newc];
                    q.push({{newr, newc}, clr});
                    visited[newr][newc] = true;
                    image[newr][newc] = color;
                }
            }
        }
        return image;
    }
};