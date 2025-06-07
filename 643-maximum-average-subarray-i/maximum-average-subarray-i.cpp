class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int j=k-1;
        int i=0;

        int sum = accumulate(nums.begin()+i, nums.begin()+k, 0);
        maxi = sum;
        j++;

        while(j < nums.size()){
            sum -= nums[i];
            sum+=nums[j];

            maxi = max(maxi, sum);
            i++;
            j++;
        }
        return maxi/(double)k;
    }
};