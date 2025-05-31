class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto no : nums){
            mp[no]++;
        }

        for(auto &[no, count] : mp){
            if(count > (nums.size()/2)){
                return no;
            }
        }
        return -1;
    }
};