class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroCount = 0, oneCount = 0, twoCount = 0;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                zeroCount++;
            }
            else if(nums[i] == 1){
                oneCount++;
            }
            else{
                twoCount++;
            }
        }

        int i=0;

        while(zeroCount--){
            nums[i++] = 0;
        }

        while(oneCount--){
            nums[i++] = 1;
        }

        while(twoCount--){
            nums[i++] = 2;
        }
    }
};