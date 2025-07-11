class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = INT_MIN;
        int sum = 0;

        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        maxSum = max(maxSum, sum);

        int i=0;
        for(int j=k; j<nums.size(); j++){
            sum += nums[j];
            sum -= nums[i++];
            maxSum = max(maxSum, sum);
        }

        return (double)(maxSum/(double)k);
    }
};