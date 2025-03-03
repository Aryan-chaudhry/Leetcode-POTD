class Solution {
public:
    int solve(vector<int>&coins, int amount, vector<int>&dp){
        // base case
        if(amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];

        int minAns = INT_MAX;
        // amount banane ke leye har coin ko use karke dekh rha hu jis jis se ban sakta hai use banakar dekhta hu

        for(int i=0; i<coins.size(); i++){
            int coin = coins[i];
            if(coin <= amount){
                // es coin se amount ban sakta hai
                int ans = solve(coins, amount-coin, dp);

                if(ans != INT_MAX){
                    int coinUsed = 1 + ans;
                   minAns = min(minAns, coinUsed);
                }
                
            }
        }
        return dp[amount] = minAns;
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int>dp(amount+1, -1);
        int ans =  solve(coins, amount, dp);
        return ans == INT_MAX || ans == 0 ? -1 : ans;
    }
};