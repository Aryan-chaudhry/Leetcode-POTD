class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos;
        vector<int>neg;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] >=0 ){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        nums.clear();
        int i=0, j=0;

        while(i < pos.size() || j < neg.size()){
            nums.push_back(pos[i++]);
            nums.push_back(neg[j++]);
        }
        return nums;
    }
    // TIME COMPLEXITY  : O(n)
    // SPACE COMPLEITY  : O(n)
};