class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long  maxValue = 0;

        for(long long i=0; i<nums.size(); i++){
            for(long long j=i+1; j<nums.size(); j++){
                for(long long k=j+1; k<nums.size(); k++){
                    long long value = ((long long)(nums[i]-nums[j])*nums[k]);
                    if(value >= maxValue){
                        maxValue = value;
                    }
                }
            }
        }
        return maxValue;
    }
};