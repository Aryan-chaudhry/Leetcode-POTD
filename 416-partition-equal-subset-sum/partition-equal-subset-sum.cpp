class Solution {
public:

    bool solve(vector<int>&nums, int sum, int& target, int index, vector<vector<int>>&dp){
        // base case
        if(index >= nums.size()) return false;
        if(sum == target) return true;
        if(sum > target) return false;

        if(dp[index][sum] != -1) return dp[index][sum];

        bool include = solve(nums, sum+nums[index], target, index+1, dp);
        bool exclude = solve(nums, sum, target, index+1, dp);

        return dp[index][sum] = include || exclude;

    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;

        int target = sum/2;
        int index = 0;
        vector<vector<int>>dp(nums.size()+1, vector<int>(sum+1, -1));
        return solve(nums,0, target, index, dp);
    }
};