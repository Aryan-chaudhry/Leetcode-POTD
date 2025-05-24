class Solution {
public:
    void solve(vector<vector<int>>&matrix, vector<vector<bool>>&visited, int m, int n){
        // make visited true where we find zero
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    visited[i][j] = true;
                }
            }
        }

        // now make that row and col 0 where visited is true
        for(int i=0; i<m;i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] == true){
                    // make that row to 0 
                    for(int col=0; col<n; col++){
                        matrix[i][col] = 0;
                    }

                    // make that col also zero
                    for(int row=0; row<m; row++){
                        matrix[row][j] = 0;
                    }
                }
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<bool>>visited(m, vector<bool>(n,false));
        solve(matrix, visited, m, n);
    }
};