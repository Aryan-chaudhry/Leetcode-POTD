class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            int count = 0;
            for(int j=0; j<nums.size(); j++){
                if(nums[j] == num){
                    count++;
                }
            }
            if(count > (nums.size()/2)){
                return nums[i];
            }
        }
        return -1;
    }
};