class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;

        int first = nums[0];
        int second = nums[0];
        int fc = 0;
        int sc = 0;

        for(int i=0; i<nums.size(); i++){
            if(fc == 0 && second != nums[i]){
                first = nums[i];
                fc = 1;
            }
            else if(sc == 0 && first != nums[i]){
                second = nums[i];
                sc = 1;
            }
            else if(first == nums[i]){
                fc++;
            }
            else if(second == nums[i]){
                sc++;
            }
            else{
                fc--;
                sc--;
            }
        }

        fc = 0;
        sc = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == first) fc++;
            else if(nums[i] == second) sc++;
        }

        if(fc > nums.size()/3) ans.push_back(first);
        if(sc > nums.size()/3) ans.push_back(second);
        return ans;
    }
};