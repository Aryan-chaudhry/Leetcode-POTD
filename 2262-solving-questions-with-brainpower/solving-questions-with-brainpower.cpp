class Solution {
public:
    long long solve(vector<vector<int>>&questions, int row, vector<long long>&dp ){
        // base case
        if(row >= questions.size()){
            return 0;
        }

        if(dp[row] != -1) return dp[row];

        // try to solve only one case
        long long maxValue = 0;
        long long value1  = questions[row][0] + solve(questions, row+questions[row][1]+1, dp);
        long long value2 = 0 + solve(questions, row+1, dp);

       return dp[row] =  maxValue = max(maxValue, max(value1, value2));
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int row = questions.size();
        int col = questions[0].size();
        vector<long long>dp(row+1, -1);
        return solve(questions, 0, dp);
    }
};