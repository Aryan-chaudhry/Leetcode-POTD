class Solution {
public:
    int solve(vector<int>&nums, int index, vector<int>&dp){
        if(index >= nums.size()-1) return 0;
        if(dp[index] != -1) return dp[index];

        int minJump = nums.size()+1;

        for(int jump=1; jump <= nums[index]; jump++){
            minJump = min(minJump, 1+solve(nums, index+jump, dp));
        }
        return dp[index] = minJump;
    }

    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1, -1);
        return solve(nums, 0, dp);
    }
};