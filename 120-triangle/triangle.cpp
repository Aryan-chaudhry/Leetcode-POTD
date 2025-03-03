class Solution {
public:
    int solve(vector<vector<int>>&triangle, int row, int col, vector<vector<int>>&dp){
        // base case
        if(row == triangle.size()-1){
            return triangle[row][col];
        }

        if(dp[row][col] != -1) return dp[row][col];

        int minAns;
        int option1 = triangle[row][col] + solve(triangle, row+1, col, dp);
        int option2 = triangle[row][col] + solve(triangle, row+1, col+1, dp);
        minAns = min(option1, option2);
        return dp[row][col] = minAns;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size()+1, vector<int>(triangle.size()+1, -1));
        return solve(triangle, 0, 0, dp);
    }
};