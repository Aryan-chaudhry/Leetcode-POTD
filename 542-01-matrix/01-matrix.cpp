class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();        
        int dist = 0;
        queue< pair < pair <int,int>, int >> q;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, dist});
                    visited[i][j] = true;
                    mat[i][j] = dist;
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int newr = r + drow[i];
                int newc = c + dcol[i];
                 if(newr >= 0 && newr < m && newc >= 0 && newc < n && !visited[newr][newc]){
                    q.push({{newr, newc}, d+1});
                    visited[newr][newc] = true;
                    mat[newr][newc] = d+1;
                 }
            }
        }
        return mat;
    }
};