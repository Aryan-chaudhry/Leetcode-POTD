class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int>store;
        int maxAns = INT_MIN;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                store.push_back(nums[i]);
            }
            else{
                int currsize = store.size();
                maxAns = max(maxAns, currsize);
                store.clear();
            }
        }
        int currsize = store.size();
        maxAns = max(maxAns, currsize);
        return maxAns;
    }
};