class Solution {
public:
    bool canJump(vector<int>& nums) {
       vector<int>dp(nums.size()+1, false);

       // analyse base in term of dp array
       dp[nums.size()-1] = true;
       dp[nums.size()] =false;

       for(int i=nums.size()-2; i>=0; i--){
            for(int jump = 1; jump<=nums[i]; jump++){
                if(i+jump < nums.size() && dp[i+jump] == true){
                    dp[i] = true;
                }
            }
       }
    return dp[0];
    }
};