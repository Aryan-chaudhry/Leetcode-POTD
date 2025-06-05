class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size()-1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[st] <= nums[mid]){
                // left part is sorted
                if(target >= nums[st] && target <= nums[mid]){
                    // target present
                    end = mid - 1;
                }
                else{
                    // target not present
                    st = mid + 1;
                }
            }
            else{
                // right part is sorted
                if(target >= nums[mid] && target <= nums[end]){
                    // target present
                    st = mid + 1;
                }
                else{
                    // target not present
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};