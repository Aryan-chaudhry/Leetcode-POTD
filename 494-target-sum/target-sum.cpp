class Solution {
public:
    void solve(vector<int>&nums, int index, int &target, int &count, int sum){
        if(index >= nums.size()){
            if(sum == target){
                count++;
            }
            return;
        }

        sum += nums[index];
        solve(nums, index+1, target, count, sum);
        sum -= nums[index];
        sum += nums[index]*-1;
        solve(nums, index+1, target, count, sum);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        int sum = 0;
        solve(nums, 0, target, count, sum);
        return count;
    }
};