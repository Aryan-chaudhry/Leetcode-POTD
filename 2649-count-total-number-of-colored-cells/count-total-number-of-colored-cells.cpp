class Solution {
public:
    long long solve(int n, vector<long long>&dp){
        if(n == 1) return 1;
        if(n == 2) return 5;
        if(dp[n] != -1) return dp[n];

        return dp[n] = (long long)(2*solve(n-1, dp) - solve(n-2, dp) + 4);
    }
    long long coloredCells(int n) {
        vector<long long>dp(n+1, -1);
        return solve(n, dp);
    }
};