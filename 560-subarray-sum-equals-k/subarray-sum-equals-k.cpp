class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        int count = 0;
        
        for(int i=0; i<nums.size(); i++){
            int sum = 0;
            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                if(sum == target){
                    count++;
                }
            }
        }
        return count;
    }
};