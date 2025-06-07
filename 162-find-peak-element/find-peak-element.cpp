class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int st = 0;
        int end = nums.size()-1;

        while(st < end){
            int mid = st + (end - st)/2;

            if(mid+1 < nums.size() && nums[mid] < nums[mid+1]){
                st = mid + 1;
            }
            else{
                end = mid;
            }
        }
        return end;
    }
};