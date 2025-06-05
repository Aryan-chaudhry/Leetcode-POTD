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

            else if(nums[st] == nums[mid] && nums[mid] == nums[end]){
                st++;
                end--;
                continue;
            }

            else if(nums[st] <= nums[mid]){
                // left  half is sorted;
                if(target >= nums[st] && target <= nums[mid]){
                    // target present
                    end = mid - 1;
                }
                else{
                    // left haft is softed but target not present
                    st = mid + 1;
                }
            }
            else{
                // right part is sorted;
                if(target >= nums[mid] && target <= nums[end]){
                    // target present in right half
                    st = mid + 1;
                }
                else{
                    // right half is sorted but target not present
                    end = mid - 1;
                }
            }
        }
        return false;
    }
};