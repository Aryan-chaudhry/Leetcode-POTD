class Solution {
public:
    bool isSafe(int digit, int i, int j, vector<vector<char>>&board){
        // check row
       for(int col=0; col<board[0].size(); col++){
            if(board[i][col] == digit) return false;
       }

       // check col
       for(int row=0; row<board.size(); row++){
            if(board[row][j] == digit) return false;
       }

       // check grid;
       for(int k=0; k<board.size(); k++){
            if(board[3*(i/3) + (k/3)][3*(j/3) + (k%3)] == digit)return false;
       }
       return true;
    }

    bool solve(vector<vector<char>>&board){
        int n = board.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == '.'){
                    // means empty
                    // lets try to place digit here

                    for(char digit='1'; digit<='9'; digit++){
                        if(isSafe(digit, i, j, board)){
                            board[i][j] = digit;
                            // rest thing is handle by recursin itself
                            bool myans = solve(board);
                            if(myans){
                                // yes posible
                                return true;
                            }
                            else{
                                // not posible, we stuck , so go back make initial state safe
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};