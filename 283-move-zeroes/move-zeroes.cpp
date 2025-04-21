class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>store;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                store.push_back(nums[i]);
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                store.push_back(nums[i]);
            }
        }

        nums = store;
    }
};