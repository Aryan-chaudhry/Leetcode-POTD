class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>leftMin(nums.size());
        vector<int>rightMax(nums.size());

        leftMin[0] = nums[0];

        for(int i=1; i<nums.size(); i++){
            leftMin[i] = min(leftMin[i-1],nums[i]);
        }

        rightMax[nums.size()-1] = nums[nums.size()-1];

        for(int i=nums.size()-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], nums[i]);
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i] > leftMin[i] && nums[i] < rightMax[i]) return true;
        }
        return false;
    }
};