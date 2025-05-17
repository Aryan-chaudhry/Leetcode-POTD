class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int st = 0, end = nums.size()-1;
        int ans = nums.size();

        while(st <= end){
            int mid = st + (end - st)/2;

            if(nums[mid] == mid){
                // till now no missing element
                st = mid + 1;
            }
            else{
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }
};