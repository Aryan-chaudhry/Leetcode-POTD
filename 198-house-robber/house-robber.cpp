class Solution {
public:
    int solve(vector<int>&nums, int i, vector<int>&dp){
        // base case
        if(i >= nums.size()){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int rob1 = nums[i] + solve(nums, i+2, dp);
        int rob2 = solve(nums, i+1, dp);

        return dp[i] =  max(rob1, rob2);

    }
    int rob(vector<int>& nums) {
        int maxi = 0;
        int i=0;
        vector<int>dp(nums.size()+1, -1);
        int ans = solve(nums, i, dp);
        return ans;
    }
};