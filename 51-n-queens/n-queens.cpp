class Solution {
public:
    bool isSafe(vector<vector<char>>&board, int row, int col, unordered_map<int,bool>&rowCheck, unordered_map<int,bool>&colCheck, unordered_map<int,bool>&upperDiagonal, unordered_map<int,bool>&lowerDiagonal){
     
        if(rowCheck[row] == true){ 
            return false;
        }
        if(colCheck[col] == true){
            return false;
        }
        if(upperDiagonal[row-col] == true){
            return false;
        }
        if(lowerDiagonal[row+col] == true){
            return false;
        }
        return true;
    }

    void giveAns(vector<vector<char>>&board, int n, vector<vector<string>>&ans){
        vector<string>output;
        
        for(int i=0; i<n; i++){
            string store = "";
            for(int j=0; j<n; j++){
                store.push_back(board[i][j]);
            }
            output.push_back(store);
        }
        ans.push_back(output);
    }

    void solve(int n, vector<vector<char>>&board, unordered_map<int,bool>&rowCheck, unordered_map<int,bool>&colCheck, unordered_map<int,bool>&upperDiagonal, unordered_map<int,bool>&lowerDiagonal, vector<vector<string>>&ans, int col ){
        // base case
        if(col >= n){
            // all queen placed successfully
            giveAns(board, n, ans);
            return;
        }

        for(int row=0; row<n; row++){
            if(isSafe(board, row, col, rowCheck, colCheck, upperDiagonal, lowerDiagonal)){
                // place queen here
                board[row][col] = 'Q';
                rowCheck[row] = true;
                colCheck[col] = true;
                upperDiagonal[row-col] = true;
                lowerDiagonal[row+col] = true;
                solve(n, board, rowCheck, colCheck, upperDiagonal, lowerDiagonal, ans, col+1);
                board[row][col] = '.';
                rowCheck[row] = false;
                colCheck[col] = false;
                upperDiagonal[row-col] = false;
                lowerDiagonal[row+col] = false;
                
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // lets create board first
        vector<vector<char>>board(n, vector<char>(n, '.'));

        // to check for safe state we have to check these condition
        // 1) row is safe
        // 2) col is safe
        // 3) upperDiagonal safe
        // 4) lowerDiagonal safe

        unordered_map<int, bool>rowCheck;
        unordered_map<int, bool>colCheck;
        unordered_map<int, bool>upperDiagonal;
        unordered_map<int, bool>lowerDiagonal;

        vector<vector<string>>ans;
        int col = 0;

        solve(n, board, rowCheck, colCheck, upperDiagonal, lowerDiagonal, ans, col);
        return ans;
    }
};