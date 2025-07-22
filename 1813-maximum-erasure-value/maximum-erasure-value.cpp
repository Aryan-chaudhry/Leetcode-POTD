class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int maxSum = 0;
        int sum = 0;
        int i = 0, j = 0;

        unordered_map<int,bool>track;

        while(j < nums.size()){
            // not present
            if(track[nums[j]] == false){
                sum += nums[j];
                track[nums[j]] = true;
                maxSum = max(maxSum, sum);
                j++;
            }
            else{
                // duplicate
                // subtract from sum and mark track false until we found duplicate
                while(track[nums[j]] == true){
                    sum -= nums[i];
                    track[nums[i]] = false;
                    i++;
                }
            }
        }
        return maxSum; 
    }
};