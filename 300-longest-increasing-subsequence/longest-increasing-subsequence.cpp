class Solution {
public:
    int recursion(vector<int>&nums, int index, int lastindex){
        // base case 
        if(index >= nums.size()){
           return 0;
        }

        int include = 0;
        int curr = nums[index];
        if(lastindex == -1 || curr > nums[lastindex]){
            include = 1 + recursion(nums, index+1, index);
        }
        int exclude = 0 + recursion(nums, index+1, lastindex);

        int LIS = max(include, exclude);
        return LIS;
    }

    int mem(vector<int>&nums, int index, int lastindex, vector<vector<int>>&dp){
        if(index >= nums.size()){
            return 0;
        }

        if(dp[index][lastindex+1] != -1){
            return dp[index][lastindex+1];
        }

        int include = 0;
        int curr = nums[index];
        if(lastindex == -1 || curr > nums[lastindex]){
            include = 1 + mem(nums, index+1, index, dp);
        }
        int exclude = 0 + mem(nums, index+1, lastindex, dp);

        dp[index][lastindex+1] = max(include, exclude);
        return dp[index][lastindex+1];
    }

    int lengthOfLIS(vector<int>& nums) {
       // 2 parameters which are changing are index and lastindex --> 2d dp
       int n = nums.size();
       vector<vector<int>>dp(n+1, vector<int>(n+3, -1));
    
        int index = 0;
        int lastindex = -1;
        return mem(nums, index, lastindex, dp);
    }
};