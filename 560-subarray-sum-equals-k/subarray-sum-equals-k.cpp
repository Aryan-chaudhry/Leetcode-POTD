class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>prefix(nums.size());
        unordered_map<int,int>mp;

        // sum k --> sum-k

        prefix[0] = nums[0];
        int count = 0;

        for(int i=1; i<nums.size(); i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i=0; i<nums.size(); i++){
            if(prefix[i] == k){
                count++;
            }

            int value = prefix[i] - k;
            if(mp.find(value) != mp.end()){
                count += mp[value];
            }
            mp[prefix[i]]++;
        }
        return count;
    }
};