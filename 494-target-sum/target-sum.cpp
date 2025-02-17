class Solution {
public:
   int Recursion(vector<int>&nums, int index, int target){
    // base case
    if(index >= nums.size()){
        return target==0 ? 1 : 0;
    }

    int plus = Recursion(nums, index+1, target+nums[index]);
    int minus = Recursion(nums, index+1, target-nums[index]);
    return plus + minus;

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = Recursion(nums, 0, target);
        return ans;
    }
};