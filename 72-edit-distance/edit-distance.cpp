class Solution {
public:
    int solve(string& word1, string& word2, int i, int j, vector<vector<int>>&dp){
        if(i >= word1.length()) 
            return word2.length()-j;
            
        if(j >= word2.length()) 
            return word1.length()-i;

        if(dp[i][j] != -1)
            return dp[i][j];
            
        int ans = 0;

        if(word1[i] == word2[j]){
            ans = 0 + solve(word1, word2, i+1, j+1, dp);
        }
        else{
            int insert = 1 + solve(word1, word2, i, j+1, dp);
            int remove = 1 + solve(word1, word2, i+1, j, dp);
            int replace = 1 + solve(word1, word2, i+1, j+1, dp);

            ans =min(insert, min(remove, replace));
        }
        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};