class Solution {
public:
  

    bool solve(vector<int>&nums){
        vector<bool>dp(nums.size()+1, false);

        dp[nums.size()-1] = true;

        for(int i=nums.size()-2; i>=0; i--){
            bool ans = false;
            for(int jump = 1; jump<=nums[i]; jump++){
                ans = ans || dp[i+jump];
            }
            dp[i] = ans;
        } 
        return dp[0];   
    }

    bool canJump(vector<int>& nums) {
        return solve(nums);
    }
};