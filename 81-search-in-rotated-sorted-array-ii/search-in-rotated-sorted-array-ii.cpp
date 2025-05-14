class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size()-1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(nums[mid] == target){
                return true;
            }
            // handle duplicate
            if(nums[st] == nums[mid] && nums[mid] == nums[end]){
                st++;
                end--;
                continue;
            }
            // first half is sorted
            else if(nums[st] <= nums[mid]){
                // cheecl target is here
                if(target >= nums[st] && target <= nums[mid]){
                    // present
                    // neglect second hlf
                    end = mid - 1;
                }
                else{
                    st = mid + 1;
                }
            }
            else{
                if(target >= nums[mid] && target <= nums[end]){
                    st = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};