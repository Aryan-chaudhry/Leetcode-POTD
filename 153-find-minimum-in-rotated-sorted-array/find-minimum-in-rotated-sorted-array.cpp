class Solution {
public:
    int findMin(vector<int>& nums) {
        int st = 0;
        int end = nums.size()-1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(mid+1 < nums.size() && nums[mid] > nums[mid+1]){
                return nums[mid+1];
            }
            else if(nums[st] > nums[mid]){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return nums[0];
    }
};