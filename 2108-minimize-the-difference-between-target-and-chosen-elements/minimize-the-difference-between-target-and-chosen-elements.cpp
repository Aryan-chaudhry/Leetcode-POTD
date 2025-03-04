class Solution {
public:
    int solve(vector<vector<int>>&mat, int sum, int row, int &target, vector<vector<int>>&dp){
        // base case
        if(row >= mat.size()){
            return abs(sum-target);
        }

        if(dp[row][sum] != -1) return dp[row][sum];

        // ek case me solve karunga
        int ans = INT_MAX;
        for(int col=0; col<mat[0].size(); col++){
            ans = min(ans, solve(mat, sum+mat[row][col], row+1, target, dp));
        }
        return dp[row][sum] = ans;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int sum = 0;
        int row = 0;
        int sumsize = 0;
        for(int i=0; i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                sumsize += mat[i][j];
            }
        }

        vector<vector<int>>dp(mat.size()+1, vector<int>(sumsize+1, -1));
        return solve(mat, sum, row, target, dp);
    }
};