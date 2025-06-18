class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = 0;
        int maxiSum = INT_MIN;

        int i=0;
        int sum = 0;

        // process the first window
        for(int st=0; st<k; st++){
            sum += nums[st];
        }

        // fetch my ans
        maxiSum = max(maxiSum, sum);
        cout << "maxiSum : " << maxiSum << endl;
        // process the remainig window
        for(int j=k; j<nums.size(); j++){
            sum += nums[j];
            sum -= nums[i];
            i++;
            maxiSum = max(maxiSum, sum);
            cout << "maxiSum : " << maxiSum << endl;
        }

        maxAvg = double(maxiSum/(double)k);
        return maxAvg;
    }
};