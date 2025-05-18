class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;

        for(int j=0; j<nums.size(); j++){
            int numsi = target-nums[j];
            if(mp.find(numsi) != mp.end()){
                return {j, mp[numsi]};
            }
            else{
                mp[nums[j]] = j;
            }
        }
        return {-1,-1};
    }
};