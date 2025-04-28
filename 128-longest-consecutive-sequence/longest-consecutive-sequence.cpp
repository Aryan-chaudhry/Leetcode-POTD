class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>store;
        int longAns = 0;

        for(int i=0; i<nums.size(); i++){
            if(store.empty()){
                store.push_back(nums[i]);
            }
            else if(nums[i] > store.back() && nums[i]-store.back() == 1){
                store.push_back(nums[i]);
            }
            else if(nums[i] == store.back()){
                continue;
            }
            else{
                int storeLength = store.size();
                longAns = max(longAns, storeLength);
                store.clear();
                store.push_back(nums[i]);
            }
        }
        int storeLength = store.size();
        longAns = max(longAns, storeLength);
        return longAns;
    }
};