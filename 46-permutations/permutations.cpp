class Solution {
public:
    void solve(vector<int>&nums, int index, vector<vector<int>>&ans){
        // base case
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int track=index; track<nums.size(); track++){
            swap(nums[index], nums[track]);
            solve(nums, index+1, ans);
            // backtracking me function automatically return ho jata hai hume bs ye check karna hita hai ki jha return hua hai vo safe hai ya nahi agar nahi to safe karo  
            swap(nums[index], nums[track]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>>ans;
        int index=0;

        solve(nums, index, ans);
        return ans;
    }
};