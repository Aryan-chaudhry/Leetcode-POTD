class Solution {
public:
    int solve(vector<int>&coins, int amount, vector<int>&dp){
        // base case
        if(amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];

        int minCoin = INT_MAX;

        for(int i=0; i<coins.size(); i++){
            if(coins[i] <= amount){
                int ans = solve(coins, amount-coins[i],dp);

                if(ans != INT_MAX){
                    int coinUsed = 1 + ans;
                    minCoin = min(minCoin, coinUsed);
                }
            }            
        }
        return dp[amount] = minCoin;
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<int>dp(amount+1,-1);
        int ans = solve(coins, amount, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};