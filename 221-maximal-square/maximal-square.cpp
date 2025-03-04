class Solution {
public:
    int solve(vector<vector<char>>& matrix, int &maxi) {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

        for (int row = matrix.size() - 1; row >= 0; row--) {
            for (int col = matrix[0].size() - 1; col >= 0; col--) {
                if (matrix[row][col] == '1') {
                    int right = dp[row][col + 1];
                    int down = dp[row + 1][col];
                    int diagonal = dp[row + 1][col + 1];

                    dp[row][col] = 1 + min({right, down, diagonal});
                    maxi = max(maxi, dp[row][col]);
                } else {
                    dp[row][col] = 0; // Fixed this line
                }
            }
        }
        return maxi; // Return maxi, squaring should be done in maximalSquare
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int ans = solve(matrix, maxi);
        return ans * ans; // Fixed, squaring should be done here
    }
};
