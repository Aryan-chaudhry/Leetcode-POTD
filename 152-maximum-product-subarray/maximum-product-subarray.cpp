class Solution {
public:
    int kadaneLR(vector<int>&nums){
        int ans = nums[0];
        int prod = 1;
        int i=0;

        while(i < nums.size()){
            prod *= nums[i];
            ans = max(ans, prod);
            if(prod ==  0) prod = 1;
            i++;
        }
        return ans;
    }

    int kadaneRL(vector<int>&nums){
        int ans = nums[nums.size()-1];
        int prod = 1;
        int i=nums.size()-1;

        while(i >= 0){
            prod *= nums[i];
            ans = max(ans, prod);
            if(prod == 0) prod = 1;
            i--;
        }
        return ans;
    }

    int maxProduct(vector<int>& nums) {
       int ans = max(kadaneLR(nums), kadaneRL(nums));
       return ans;
    }
};