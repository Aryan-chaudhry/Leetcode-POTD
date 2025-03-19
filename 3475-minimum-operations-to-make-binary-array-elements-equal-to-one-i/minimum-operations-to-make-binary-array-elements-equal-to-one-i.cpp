class Solution {
public:
    int minOperations(vector<int>& nums) {
        // maintain window size
        int i=0, j=3-i-1;
        int count = 0;

        while(j < nums.size()){
            // check if window ith element equals to zero flip whole window and increment count otherwise shift the window by 1

            if(nums[i] == 0){
                for(int st = i; st<=j; st++){
                    if(nums[st] == 0){
                        nums[st] = 1;
                    }
                    else{
                        nums[st] = 0;
                    }
                }
                count++;
            }
            else{
                i++;
                j++;
            }
        }
        

        for(int st=0; st<nums.size(); st++){
            if(nums[st] == 0){
                return -1;
            }
        }
        return count;
    }
};