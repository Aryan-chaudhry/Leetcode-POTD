class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        // element hi ek hai    
        if(nums.size() == 1){
            return 0;
        }

        if(nums.size() == 2){
            if(nums[0] > nums[1]){
                return 0;
            }
            else{
                return 1;
            }
        }


        int st = 1;
        int end = nums.size()-2;

        int mid = st + (end - st)/2;

        while(st <= end){
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }

            else if(nums[mid-1] > nums[mid]){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
            // update mid;
            mid = st + (end - st)/2;
        }
        if(nums[0] > nums[nums.size()-1]){
            return 0;
        }
        return nums.size()-1;
    }
};