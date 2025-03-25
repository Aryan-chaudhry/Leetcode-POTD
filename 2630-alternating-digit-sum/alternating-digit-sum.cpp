class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int>nums;

        while(n != 0){
            int digit = n % 10;
            nums.push_back(digit);
            n /= 10;
        }

        reverse(nums.begin(), nums.end());

        int sum = 0;
       

       for(int i=0; i<nums.size(); i++){
            if(i%2 == 0 || i == 0){
                sum += nums[i];
            }
            else{
                sum -= nums[i];
            }
       }
       return sum;
    }
};