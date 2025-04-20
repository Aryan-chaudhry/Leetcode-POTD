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

    bool check(vector<int>& nums) {
        int position = -1;

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                position = i;
                break;
            }
        }

        if(position == -1) return true;

        vector<int>ans;

        for(int i=position+1; i<nums.size(); i++){
            ans.push_back(nums[i]);
        }

        for(int i=0; i <= position; i++){
            ans.push_back(nums[i]);
        }

        if(isSorted(ans)){
            return true;
        }
        return false;
    }
};