class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=i+1;
        while(j < nums.size()){
            // 2 cases
            // no are equal
            if(nums[i] == nums[j]){
                j++;
            }
            // no is different
            else{
                i++;
                nums[i] = nums[j];
            }

        }
        return i+1;
    }
};