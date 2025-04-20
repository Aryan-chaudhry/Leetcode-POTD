class Solution {
public:
    bool isSorted(vector<int>&ans){
        for(int i=0; i<ans.size()-1; i++){
            if(ans[i] > ans[i+1]){
                return false;
            }
        }
        return true;
    }

    void reverse(int st, int end, vector<int>&nums){
        while(st <= end){
            swap(nums[st++], nums[end--]);
        }
    }

    bool check(vector<int>& nums) {
        int position = -1;

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                position = i;
                break;
            }
        }

        if(position == -1) return true;

        reverse(position+1, nums.size()-1, nums);
        reverse(0, position, nums);
        reverse(0, nums.size()-1, nums);



        if(isSorted(nums)){
            return true;
        }
        return false;
    }
    // TIME COMPLEXITY  O(n)
    // SPACE COMPLEXITY O(1)
};