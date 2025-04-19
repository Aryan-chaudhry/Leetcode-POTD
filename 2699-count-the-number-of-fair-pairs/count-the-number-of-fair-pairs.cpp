class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;
        deque<int>dq;

        for(auto no : nums){
            dq.push_back(no);
        }

        for(int i=0; i<nums.size(); i++){
            dq.pop_front();
            auto lb = lower_bound(dq.begin(), dq.end(), lower-nums[i]);
            auto up = upper_bound(dq.begin(), dq.end(), upper-nums[i]);
            count += (up-lb);
        }
        return count;
    }
};