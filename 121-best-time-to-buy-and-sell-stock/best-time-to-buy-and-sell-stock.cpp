class Solution {
public:
    int solve(vector<int>&arr, int index, int &buy, vector<int>&dp){
        if(index >= arr.size()) return 0;
        if(dp[index] != -1) return dp[index];

        int maxProfit = INT_MIN;

        if(arr[index] < buy){
            maxProfit =  solve(arr, index+1, arr[index], dp);
        }
        else{
            maxProfit = max(arr[index]-buy, solve(arr, index+1, buy, dp));
        }
        return dp[index] =  maxProfit;    
    }

    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        vector<int>dp(prices.size()+1, -1);
        return solve(prices, 1, buy, dp);
    }
};